#include "TimerThread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace SM
{
TimerThread::TimerThread(TimerCallback cb, int initialTime, int intervalTime)
: _timer(Timer(cb, initialTime, intervalTime))
, _thread(std::bind(&Timer::start, &_timer))
{}

void TimerThread::start()
{
	_thread.start();
}

void TimerThread::stop()
{
	_timer.stop();
	cout << "timer stop ---" << endl;
	_thread.join();
}

} //end of namespace SM
