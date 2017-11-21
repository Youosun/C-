#ifndef _SM_CONDITION_H__
#define _SM_CONDITION_H__

#include "MutexLock.h"
#include <pthread.h>

namespace SM
{
class MutexLock;

class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();
	
	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace SM

#endif
