#ifndef __SM_CONDITION_H__
#define __SM_CONDITION_H__

#include "Nocopyable.h"
#include <pthread.h>

namespace SM
{
class MutexLock;
class Condition
: Noncopyable
{
public:
	explicit// 避免发生隐式转换
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyall();

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

} //end of namespace SM

#endif
