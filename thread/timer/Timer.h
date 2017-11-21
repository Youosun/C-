#ifndef _SM_TIMER_H__
#define _SM_TIMER_H__

#include <functional>

namespace SM
{

class Timer
{
public:
	typedef std::function<void()> TimerCallback;

	Timer(TimerCallback cb, int initialTime, int intervalTime);
	~Timer();

	void start();
	void stop();
private:
	int createTimerfd();
	void setTimerfd(int initialTime, int intervalTime);
	void handleRead();
private:
	int _fd;
	TimerCallback _cb;
	int _initialTime;
	int _intervalTime;
	bool _isStarted;
};

} //end of namespace SM

#endif
