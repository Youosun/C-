#ifndef _SM_CONSUMER_H__
#define _SM_CONSUMER_H__

#include "Thread.h"
#include <pthread.h>

namespace SM
{
class TaskQueue;
class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & que);

	void run();
	
private:
	TaskQueue & _que;
};

} //end of namespace SM

#endif
