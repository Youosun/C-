#include "Thread.h"
#include <pthread.h>

namespace SM
{
Thread::Thread(threadCallback && cb)
: _isRunning(false)
, _pthId(0)
, _cb(std::move(cb))
{}

Thread::~Thread()
{
	if(_isRunning)
		pthread_detach(_pthId);
		_isRunning = false;
}

void Thread::start() //调用的始终是Thread的派生类
{
	pthread_create(&_pthId, NULL, threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning)
	{
		pthread_join(_pthId, NULL);
		_isRunning = false;
	}
}

void * Thread::threadFunc(void * arg)  
{
	//threadFunc的任务就是去执行Thread的回调函数
	//此时的pthread真实指向创建的对象  不同的对象代表了注册了不同的回调函数  执行不同的任务
	//而不是通过虚函数继承机制 通过多态来实现
	//
	//这就是基于对象和面向对象的区别  通过回调函数解决多态问题
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
	{
		pthread->_cb();
	}
	return 0;
}

} //end of namespace SM
