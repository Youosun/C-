#include "pthread_mutex.h"

#include <iostream>
using namespace std;

//mutex 与 condition各自负责自己的生命周期
//它们之间相互独立  所以cond类中不能包含普通成员变量mutex

class Condition
{
public:
	Condition(Mutex & mutex)
	: _mutex(mutex)
	{
		pthread_cond_init(&_cond, NULL);
	}

	void wait()
	{
		pthread_cond_wait(&_cond, _mutex.getMutexPtr());
	}

	~Condition()
	{
		pthread_cond_destroy(&_cond);
	}

	void notify()
	{
		pthread_cond_signal(&_cond);
	}

	void notifyall()
	{
		pthread_cond_broadcast(&_cond);
	}
private:
	pthread_cond_t _cond;
	Mutex &_mutex; //关联关系  A has B  反向不成立 
					//condition 的存在依赖于mutex mutex的存在并不依赖于condition
};
