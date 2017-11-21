#include "Producer.h"
#include "TaskQueue.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
using namespace std;

namespace SM
{
Producer::Producer(TaskQueue & que)
: _que(que)
{}

void Producer::run()
{
	::srand(time(NULL));
	while(true)
	{
		int num = ::rand() % 100;
		_que.push(num);
		cout << "produce a number: " << num << endl;
		::sleep(1);
	}
}

} //end of namespace SM
