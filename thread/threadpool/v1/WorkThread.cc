#include "WorkThread.h"
#include "Threadpool.h"
#include <iostream>
using namespace std;

namespace SM
{
WorkThread::WorkThread(Threadpool & threadpool)
: _threadpool(threadpool)
{}	

void WorkThread::run()
{
	_threadpool.threadFunc(); //工作线程并不负责取队列元素  调用线程池的成员函数取队列
}

}//end of namespace SM
