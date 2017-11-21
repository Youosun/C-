#ifndef __SM_WORKTHREAD_H__
#define __SM_WORKTHREAD_H__

#include "Thread.h"

namespace SM
{

class Threadpool;
class WorkThread
: public Thread
{
public:
	WorkThread(Threadpool & threadpool);
	//使用线程池对象初始化工作线程
	//理解: 每个工人都隶属于某个包工头
	//		将其关联起来

private:
	void run();
private:
	Threadpool & _threadpool;
};

}//end of namespace SM

#endif
