#include "Producer.h"
#include "Consumer.h"
#include "TaskQueue.h"
#include <memory>
#include <iostream>
using namespace std;

int main()
{
	SM::TaskQueue tq(5);
	
	std::unique_ptr<SM::Producer> pProduce(new SM::Producer(tq));
	std::unique_ptr<SM::Consumer> pConsumer(new SM::Consumer(tq));

	pProduce->start();
	pConsumer->start();

	pProduce->join();
	pConsumer->join();


	return 0;
}
