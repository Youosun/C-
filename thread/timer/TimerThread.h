#ifndef _SM_TIMERTHREAD_H__
#define _SM_TIMERTHREAD_H__

#include "Timer.h"
#include "Thread.h"

#include <functional>

namespace SM
{

class TimerThread
{
public:
	typedef std::function<void()> TimerCallback;
	TimerThread(TimerCallback cb, int initialTime, int intervalTime);

	void start();
	void stop();
private:
	Timer _timer;
	Thread _thread;
};

} //end of namespace SM

#endif
