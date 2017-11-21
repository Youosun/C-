#include "TimerThread.h"
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;

class MyTask
{
public:
	void task()
	{
		::srand(time(NULL));
		int number = ::rand() % 100;
		cout << "produce a number: " << number << endl;
	}

};

void getRandomNumber()
{
	::srand(time(NULL));
	int number = ::rand() % 100;
	cout << "produce a number: " << number << endl;
}

int main()
{
	SM::TimerThread timer(getRandomNumber, 1, 3);
	timer.start();

	::sleep(10);
	timer.stop(); //一般调用终止在不同的线程

	return 0;
}
