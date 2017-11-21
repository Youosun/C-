#include <iostream>
using namespace std;

class Queue
{
public:
	Queue(int size)
	: _size(size)
	, _front(0)
	, _rear(0)
	, _arr(new int [_size]())
	{

	}

	~Queue()
	{
		delete [] _arr;
	}

	bool full() const
	{
		return _front == (_rear + 1) % _size;
	}

	bool empty() const
	{
		return _front == _rear;
	}

	void push(const int & val)
	{
		if(!full())
		{
			_arr[_rear++] = val;
			_rear %= _size;
		}
		else{
			cout << "Queue is full" << endl;
		}
	}

	void pop()
	{
		if(!empty())
		{
			++_front;
			_front %= _size;
		}
		else{
			cout << "Queue is empty" << endl;
		}
	}

	int front()const
	{
		return _arr[_front];
	}

	int rear()const
	{
		return _arr[(_rear - 1 + _size) % _size];
	}
private:
	int _size;
	int _front;
	int _rear;
	int * _arr;
};

int main(void)
{
	Queue qu(10);
	cout << "Is Queue empty?" << qu.empty() << endl;
	qu.push(1);
	cout << "Is Stack empty?" << qu.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		qu.push(idx);
	}
	cout << "Is Stack empty?" << qu.empty() << endl;

	while(!qu.empty())
	{
		cout << qu.front() << endl;
		qu.pop();
	}

	cout << "The front member:" << qu.front() << endl;
	cout << "The rear member: " << qu.rear() << endl;

	return 0;
}
