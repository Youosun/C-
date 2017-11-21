#ifndef _SM_THREAD_H__
#define _SM_THREAD_H__

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace SM
{
class Thread
: Noncopyable
{
public:
	typedef std::function<void()> threadCallback;

	Thread(threadCallback && cb);
	~Thread();

	void start();//这两种方法都是在主线程中调用  
	void join(); //由主线程启动和回收子线程
private:
	static void * threadFunc(void*);
private:
	bool _isRunning;
	pthread_t _pthId;
	threadCallback _cb;
};

} //end of namespace SM

#endif
