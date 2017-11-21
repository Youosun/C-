#include "Thread.h"
#include "Threadpool.h"

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace SM
{
Threadpool::Threadpool(size_t threadNum, size_t queSize)
: _threadNum(threadNum)
, _queSize(queSize)
, _taskQue(_queSize) //que中存放的时函数对象  可直接运行
, _isExit(false)
{
	_threads.reserve(_threadNum);
}

Threadpool::~Threadpool()
{
	if(!_isExit)
	{
		stop();
	}
}

void Threadpool::start()
{
	for(size_t idx = 0; idx != _threadNum; ++idx)
	{
		shared_ptr<Thread> sp(new Thread(std::bind(&Threadpool::threadFunc, this)));
		_threads.push_back(sp);
	}

	for(auto & thread : _threads)
		thread->start();
}

void Threadpool::stop()
{
	if(!_isExit)
	{
		while(!_taskQue.empty())
		{
			::sleep(2);
		}
		_isExit = true;
		//当子线程运行速度快于主线程时,
		//子线程会阻塞在_taskQue.pop方法上
		//此时需要激活_taskQue内部的条件变量
		_taskQue.wakeup();

		for(auto & thread : _threads)
		{
			thread->join();
		}
	}
}

void Threadpool::addTask(Task && task)
{
	_taskQue.push(std::move(task));
}

Task Threadpool::getTask()
{
	return _taskQue.pop();
}

void Threadpool::threadFunc()
{
	while(!_isExit)
	{
		Task task = getTask(); 
		if(task)
			task();
	}
}

}
