#include "Thread.h"
#include "TaskQueue.h"

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

class Producer
{
public:
	void makeNumber(SM::TaskQueue & queue)
	{
		::srand(time(NULL));
		while(true)
		{
			int number = ::rand() % 100;
			cout << "produce a number: " << number << endl;
			queue.push(number);
			::sleep(1);
		}
	}
};

class Consumer
{
public:
	void getNumber(SM::TaskQueue & queue)
	{
		while(true)
		{
			int number = queue.pop();
			cout << "consume a number: " << number << endl;
			::sleep(1);
		}
	}
};

int main(void)
{
	SM::TaskQueue tq(10);

	SM::Thread producer(std::bind(&Producer::makeNumber, Producer(), std::ref(tq)));
	SM::Thread consumer(std::bind(&Consumer::getNumber, Consumer(), std::ref(tq)));

	producer.start();
	consumer.start();

	producer.join();
	consumer.join();

	return 0;
}
