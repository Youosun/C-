#include <iostream>
#include <string>
using namespace std;

template <typename T, int kSize = 10>
class Queue
{
public:
	Queue()
	: _size(kSize)
	, _front(0)
	, _rear(0)
	, _arr(new T[_size]())
	{}

	~Queue();

	bool full() const;
	bool empty() const;

	void push(const T & val);
	void pop();

	T front() const;
	T rear() const;

private:
	int _size;
	int _front;
	int _rear;
	T * _arr;
};

template <typename T, int kSize>
Queue<T, kSize>::~Queue()
{
	delete [] _arr;
}

template <typename T, int kSize>
bool Queue<T, kSize>::full() const
{
	return _front == (_rear + 1) % _size;
}

template <typename T, int kSize>
bool Queue<T, kSize>::empty() const
{
	return _front == _rear;
}

template <typename T, int kSize>
void Queue<T, kSize>::push(const T & val)
{
	if(!full())
	{
		_arr[_rear++] = val;
		_rear %= _size;
	}
	else
	{
		cout << "队列已满" << endl;
	}
}

template <typename T, int kSize>
void Queue<T, kSize>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= _size;
	}
	else
	{
		cout << "队列已空" << endl;
	}
}

template <typename T, int kSize>
T Queue<T, kSize>::front()const
{
	return _arr[_front];
}

template <typename T, int kSize>
T Queue<T, kSize>::rear() const
{
	return _arr[(_rear - 1 + _size) % _size]; //此处重点
}

int test0(void)
{
	Queue<int> que;
	cout << "Is queue empty?" << que.empty() << endl;
	que.push(1);
	cout << "Is queue empty?" << que.empty() << endl;

	for(int idx = 2; idx != 12; ++ idx)
	{
		que.push(idx);
	}
	cout << "Is queue empty?" << que.empty() << endl;

	cout << "The front member = " << que.front() << endl;
	cout << "The rear member = " << que.rear() << endl;

	while(!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	cout << "The front member = " << que.front() << endl;
	cout << "The rear member = " << que.rear() << endl;

	return 0;
}

int main(void)
{
	Queue<string> que;
	cout << "Is queue empty?" << que.empty() << endl;
	que.push("AAAA");
	cout << "Is queue empty?" << que.empty() << endl;

	for(int idx = 1; idx != 11; ++ idx)
	{
		string tmp(4, 'A' + idx);
		que.push(tmp);
	}
	cout << "Is queue empty?" << que.empty() << endl;

	cout << "The front member = " << que.front() << endl;
	cout << "The rear member = " << que.rear() << endl;

	while(!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}

	cout << "The front member = " << que.front() << endl;
	cout << "The rear member = " << que.rear() << endl;

	return 0;
}

