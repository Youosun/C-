#include "Timer.h"

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/timerfd.h>
#include <poll.h>

#include <iostream>
using std::cout;
using std::endl;

namespace SM
{
Timer::Timer(TimerCallback cb, int initialTime, int intervalTime)
: _fd(createTimerfd())
, _cb(cb)
, _initialTime(initialTime)
, _intervalTime(intervalTime)
, _isStarted(false)
{}

Timer::~Timer()
{
	if(_isStarted)
		stop();
}

void Timer::start()
{
	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	_isStarted = true;
	setTimerfd(_initialTime, _intervalTime);
	while(_isStarted)
	{
		int nready = ::poll(&pfd, 1, 5000);
		if(nready == -1 && errno == EINTR)
			continue;
		else if(nready == -1)
		{
			cout << "> poll error! " << endl;
			return ;
		}
		else{
			if(pfd.fd == _fd && (pfd.revents & POLLIN))
			{
				handleRead(); //处理定时器的操作
				if(_cb)
					_cb();
			}
		}
	}
}

void Timer::stop()
{
	setTimerfd(0, 0);
	if(_isStarted)
	{
		_isStarted = false;
		cout << "setTimerfd 0 0 ---" << endl;
	}
}

int Timer::createTimerfd()
{
	int fd = ::timerfd_create(CLOCK_REALTIME, 0);
	if(fd == -1)
	{
		perror("timerfd_create error");
	}
	return fd;
}

void Timer::setTimerfd(int initialTime, int intervalTime)
{
	struct itimerspec value;
	value.it_value.tv_sec = initialTime;
	value.it_value.tv_nsec = 0;
	value.it_interval.tv_sec = intervalTime;
	value.it_interval.tv_nsec = 0;

	int ret = timerfd_settime(_fd, 0, &value, NULL);
	if(ret == -1)
	{
		perror("timerfd_settime error");
	}
}

void Timer::handleRead()
{
	uint64_t howmany;
	int ret = ::read(_fd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany))
	{
		perror("> read error");
	}
}

}
