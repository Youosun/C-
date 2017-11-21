#include "Thread.h"
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
using namespace std;

class MyThread
: public wd::Thread
{
private:
	void run()
	{
		::srand(time(NULL));
		while(true)
		{
			int number = ::rand() % 100;
			cout << "produce a number: " << number << endl;
			::sleep(1);
		}
	}
};

int main(void)
{
	wd::Thread * pthread = new MyThread();
	pthread->start();
	pthread->join();

	delete pthread;
	return 0;
}
