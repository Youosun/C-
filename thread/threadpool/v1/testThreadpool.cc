#include "Threadpool.h"
#include "Task.h"

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <memory>

using namespace std;

class MyTask
: public SM::Task
{
public:
	void process()
	{
		::srand(::time(NULL));
		int num = ::rand() % 100;
		cout << "Produce a number: " << num << endl;
		::sleep(1);
	}
};

int main(void)
{
	unique_ptr<SM::Task> task(new MyTask);

	SM::Threadpool threadpool(4, 10);
	threadpool.start();

	int cnt = 20;
	while(cnt--)
	{
		threadpool.addTask(task.get());
		cout << "cnt = " << cnt << endl;
	}

	threadpool.stop();

	return 0;
}
