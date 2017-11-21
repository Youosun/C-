#include "MutexLock.h"
#include <iostream>
#include <pthread.h>

namespace SM
{
MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	_isLocking = false;
	pthread_mutex_unlock(&_mutex);
}

pthread_mutex_t * MutexLock::getMutexPtr()
{
	return &_mutex;
}

bool MutexLock::islocking()
{
	return _isLocking;
}

}// end of namespace SM
