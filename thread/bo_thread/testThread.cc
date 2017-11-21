#include "Thread.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class MyTask
{
public:
	void run()
	{
		::srand(time(NULL));
		while(true)
		{
			int number = rand() % 100;
			cout << "produce a number: " << number << endl;
			::sleep(1);
		}
	}
};

void getRandNum()
{
	::srand(time(NULL));
	while(true)
	{
		int number = rand() % 100;
		cout << "produce a number: " << number << endl;
		::sleep(1);
	}
}

int main(void)
{
//	wd::Thread pthread(std::bind(&MyTask::run, MyTask()));
	wd::Thread pthread(std::bind(getRandNum));

	pthread.start();
	pthread.join();

	return 0;
}
