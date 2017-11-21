#ifndef __SM_MUTEX_H__
#define __SM_MUTEX_H__

#include "Nocopyable.h"
#include <pthread.h>

namespace SM
{
class MutexLock
: Noncopyable
{
public:
	MutexLock();
	~MutexLock();

	void lock();

	void unlock();
	
	pthread_mutex_t * getMutexLock();

	bool islocking()const;
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard//RAII技术
{
public:
	MutexLockGuard(MutexLock & mutexlock)
	: _mutexlock(mutexlock)
	{
		_mutexlock.lock();	
	}	

	~MutexLockGuard()
	{
		_mutexlock.unlock();
	}
private:
	MutexLock & _mutexlock;

};


}// end of namespace sm




#endif
