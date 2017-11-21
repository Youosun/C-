#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

namespace wd
{
class Thread
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();
private:
	virtual void run()=0;  //由派生类自定义具体的入口函数
	static void * threadFunc(void *); //线程的入口函数
										//去除this参数  采用static
private:
	pthread_t _pthId;
	bool _isRunning;
};


}//end of namespace wd

#endif
