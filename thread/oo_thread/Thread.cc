#include "Thread.h"
#include <iostream>
using namespace std;

namespace wd
{

Thread::Thread()
: _pthId(0)
, _isRunning(false)
{}

Thread::~Thread()
{
	if(_isRunning)
		pthread_detach(_pthId);
		_isRunning = false;
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
{//threadFunc就是来执行派生类自定义的run()  线程入口函数
	Thread * pthread = static_cast<Thread*>(arg); //传入的参数是this指针 指向派生类对象
	if(pthread)
		pthread->run();

	return NULL;
}

}
