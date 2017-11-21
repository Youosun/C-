#include "Threadpool.h"
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

class MyTask
{
public:
	void process()
	{
		::srand(::clock());
		int num = ::rand() % 100;
		cout << "produce a number: " << num << endl;
		::sleep(1);
	}
};
