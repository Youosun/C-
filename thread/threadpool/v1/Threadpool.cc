#include "Threadpool.h"
#include "WorkThread.h"
#include "Task.h"

#include <unistd.h>
#include <iostream>
namespace SM
{

Threadpool::Threadpool(size_t threadnum, size_t tasknum)
: _threadNum(threadnum)
, _taskNum(tasknum)
, _taskQue(tasknum)
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
	for(size_t idx = 0; idx != _threadNum; ++idx)//制造线程
	{
		shared_ptr<Thread> sp(new WorkThread(*this));
		_threads.push_back(sp);
	}

	for(auto & thread : _threads)//分别启动每个线程
	{
		thread->start();
		cout << "init" << endl;
	}
}

void Threadpool::stop() //主进程调用
{
	if(!_isExit)//这里相当于来了一个信号  表明要关闭线程池
	{
		while(!_taskQue.empty())//当任务队列中没有元素时 可以关闭线程池
		{
			::sleep(1);//等待任务队列被取空
		}
		_isExit = true; //更改标志  向全局通知要退出
		_taskQue.wakeup();//使得仍然阻塞在获取任务上的线程 收到信号

		//当子线程进行的比较快时
		//主线程还未将_isExit标志设置为true时,
		//子线程已经进入threadFunc函数中  并阻塞在getTask()中  造成死锁状态

		for(auto & thread : _threads)
		{
			thread->join();
		}
	}
}

//充当的是生产者角色
void Threadpool::addTask(Task * task)
{
	_taskQue.push(task);
}

Task * Threadpool::getTask()
{
	return _taskQue.pop();
}

void Threadpool::threadFunc() //由workthread进行调用  从任务队列当中取任务  并执行任务中的process()
{//子线程要执行的函数, 充当了消费者的角色
//	while(!_isExit && !_taskQue.empty())
	while(!_isExit)
	{
		Task * task = getTask(); //当队列为空时 会阻塞
		if(task)
		{
			task->process();
		}
	}
}

}//end of namespace SM
