#include "Thread.h"

namespace SM
{
Thread::Thread(ThreadCallback && cb)
: _pthId(0)
, _isRunning(false)
, _cb(std::move(cb))
{}

Thread::~Thread()
{
	if(_isRunning)
	{
		pthread_detach(_pthId);
		_isRunning = false;
	}
}

void Thread::start()
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
	//threadFunc的任务就是执行实际注册在Thread对象中的回调函数
	//threadFunc可以提供统一的接口
	Thread * pThis = static_cast<Thread*>(arg);
	if(pThis)
		pThis->_cb();

	return NULL;
}

}//end of namespace SM
