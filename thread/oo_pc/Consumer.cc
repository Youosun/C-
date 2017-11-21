#include "Consumer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <iostream>
using namespace std;

namespace SM
{
Consumer::Consumer(TaskQueue & que)
: _que(que)
{}

void Consumer::run()
{
	while(true)
	{
		int number = _que.pop();
		cout << "Consumer: consume a number: " << number << endl;
		::sleep(1);
	}
}

} // end of namespace SM
