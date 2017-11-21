#ifndef __SM_TASKQUEUE_H__
#define __SM_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"

#include <iostream>
#include <queue>
using namespace std;

namespace SM
{
class Task;

class TaskQueue
{
public:
	typedef Task * ElemType;

	TaskQueue(size_t size);

	void push(const ElemType & elem);
	ElemType pop();

	void wakeup();

	bool full()const;

	bool empty()const;
private:
	size_t _size;
	bool _flag;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};

} //end of namepsace Sm

#endif
