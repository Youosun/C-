#include "pthread_mutex.h"

#include <iostream>
using namespace std;

Mutex mutex;

int test(void)
{
	MutexLockGuard mtg(mutex);  //使用栈对象mtg特性---函数栈退出时自动调用析构函数  解锁mutex
	mutex.Lock();				//防止因为意外退出造成的死锁现象
	//
	//doSomething()
	//
	mutex.Unlock();

	return 0;
}

int main(void)
{}
