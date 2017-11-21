#ifndef __SM_THREAD_H__
#define __SM_THREAD_H__	

#include "Nocopyable.h"
#include <pthread.h>

namespace SM
{
class Thread
{
public:
	Thread();
	virtual ~Thread();

	void start();
	void join();
private:
	virtual void run()=0;
	static void * threadFunc(void*);
private:
	pthread_t _pthId;
	bool _isRunning;
};

}//end of namespace SM


#endif
