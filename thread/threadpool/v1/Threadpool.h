#ifndef __SM_THREADPOOL_H__
#define __SM_THREADPOOL_H__

#include "TaskQueue.h"

#include <vector>
#include <memory>

namespace SM
{
class Thread;
class Task;
class WorkThread;

class Threadpool
{
	friend WorkThread;
public:
	Threadpool(size_t threadnum, size_t tasknum);

	~Threadpool();

	void start();
	void stop();
	void addTask(Task *);
private:
	void threadFunc();

	Task * getTask();
private:
	size_t _threadNum;
	size_t _taskNum;
	vector<shared_ptr<Thread>> _threads;

	TaskQueue _taskQue;
	bool _isExit;
};

}//end of namespace SM

#endif
