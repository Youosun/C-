#ifndef __SM_MUTEXLOCK_H__
#define __SM_MUTEXLOCK_H__

#include "Noncopyable.h"
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

	pthread_mutex_t * getMutexPtr();

	bool islocking();
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
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

} // end of namespace SM

#endif
