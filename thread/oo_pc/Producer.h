#ifndef _SM_PRODUCER_H__
#define _SM_PRODUCER_H__

#include "Thread.h"
#include "TaskQueue.h"


namespace SM
{
class Producer
: public Thread
{
public:
	Producer(TaskQueue & que);

	void run();
private:
	TaskQueue & _que;
};

}//end of namespace SM

#endif
