#ifndef MUTEX_COND_PTHREAD_MUTEX_H__
#define MUTEX_COND_PTHREAD_MUTEX_H__  //项目名_路径名_文件名__

#include <pthread.h>

#include <iostream>
using namespace std;

class Mutex
{
public:
	Mutex()
	: _islocked(false)
	{
		pthread_mutex_init(&_mutex, NULL);
	}

	pthread_mutex_t * getMutexPtr()
	{
		return &_mutex;
	}

	~Mutex()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void Lock()
	{
		_islocked = true;
		pthread_mutex_lock(&_mutex);
	}

	void Unlock()
	{
		_islocked = false;
		pthread_mutex_unlock(&_mutex);
	}

	bool isLocking()
	{
		return _islocked;
	}
private://通过语法机制表达语义
	Mutex(const Mutex &);//禁止复制  对象语意
	Mutex & operator=(const Mutex &);
private:
	pthread_mutex_t _mutex;
	bool _islocked;
};

//利用栈对象程序结束时自动调用析构函数释放的特性
//定义一个守卫，起到保护作用，防止发生死锁
class MutexLockGuard
{
public:
	MutexLockGuard(Mutex & mutex)
	: _mutex(mutex)
	{
		_mutex.Lock();
	}

	~MutexLockGuard()
	{
		_mutex.Unlock();
	}
private:
	Mutex & _mutex;
};


#endif
