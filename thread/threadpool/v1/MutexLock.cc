#include "MutexLock.h"

namespace SM
{
MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

void MutexLock::lock()
{
	_isLocking = true;
	pthread_mutex_lock(&_mutex);
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);	
	_isLocking = false;
}

pthread_mutex_t * MutexLock::getMutexLock()
{
	return &_mutex;
}

bool MutexLock::islocking()const
{
	return _isLocking;
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

}//end of namespace SM
