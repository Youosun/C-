#ifndef _SM_TASKQUEUE_H__
#define _SM_TASKQUEUE_H__

#include "MutexLock.h"
#include "Condition.h"
#include <queue>
using namespace std;

namespace SM
{
class TaskQueue
{
public:
	typedef int ElemType;

	TaskQueue(size_t size);

	void push(const ElemType & elem);
	ElemType pop();

	bool full() const;
	bool empty() const;
private:
	size_t _size;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;	
};


} //end of namespace SM





#endif
