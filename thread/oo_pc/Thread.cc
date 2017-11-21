#include "Thread.h"
#include <pthread.h>

namespace SM
{
Thread::Thread()
: _isRunning(false)
, _pthId(0)
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
	Thread * pthread = static_cast<Thread*>(arg);
	if(pthread)
	{
		pthread->run();
	}
	return NULL;
}

} //end of namespace SM
