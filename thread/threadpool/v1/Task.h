#ifndef __SM_TASK_H__
#define __SM_TASK_H__

namespace SM
{
class Task
{
public:
	virtual void process()=0; //虚基类  定义具体执行的工作
};

}//end of namespace SM


#endif
