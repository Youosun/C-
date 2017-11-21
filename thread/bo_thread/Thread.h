#ifndef __WD_THREAD_H__
#define __WD_THREAD_H__

#include <pthread.h>
#include <functional>

namespace wd
{
class Thread
{
public:
	typedef std::function<void()> ThreadCallback;  //线程具体的taskFunc;

	Thread(ThreadCallback && cb);
	~Thread();

	void start();
	void join();

private:
	static void * threadFunc(void *);
private:
	pthread_t _pthId;
	bool _isRunning;
	ThreadCallback _cb;
};

}//end of namespace wd

#endif
