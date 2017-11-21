#include "TaskQueue.h"
#include <iostream>
using namespace std;

namespace SM
{
TaskQueue::TaskQueue(size_t size)
: _size(size)
, _flag(true)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{
}

bool TaskQueue::full()const
{
	return _que.size() == _size;
}

bool TaskQueue::empty()const
{
	return _que.empty();
}

void TaskQueue::wakeup()
{
	_flag = false;
	_notEmpty.notifyall();
}

//该方法的调用是在生产者线程中
void TaskQueue::push(const ElemType & elem)
{
	MutexLockGuard mlg(_mutex);//1. 能够保证该函数在执行过程中不会发生因异常退出造成的死锁现象
	while(full())//2. 为了防止等待在该条件变量上的线程被异常唤醒  
	{			//	   要使用while判断 -- 等待唤醒后再次判断  不能使用if
		_notFull.wait(); //等待该TaskQueue不满  该条件有可能被异常唤醒  
	}
	_que.push(elem);//放数据
	_notEmpty.notify();//3. 通知消费者线程 -- 现在非空
}

//该方法的调用是在消费者线程里面
TaskQueue::ElemType TaskQueue::pop()
{
	//_mutex.lock();
	
	MutexLockGuard mlg(_mutex);  //在初始化mlg时lock()  函数退出时unlock()  避免异常退出造成死锁
	while(_flag && empty())
	{
		_notEmpty.wait();
	}
	TaskQueue::ElemType temp = _que.front();//取数据
	_que.pop();
	_notFull.notify();//通知生产者线程  现在队列不满  可以添加数据

	return temp;
}

}//end of namespace SM
