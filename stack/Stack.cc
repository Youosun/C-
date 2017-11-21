#include <iostream>
using namespace std;


class Stack
{
public:
	Stack(int size)
	: _top(-1)
	, _size(size)
	, _arr(new int [_size]())
	{
	}

	~Stack()
	{
		delete [] _arr;
	}

	bool full()const
	{
		return _top == _size - 1;
	}

	bool empty()const
	{
		return _top == -1;
	}

	void push(const int & val)
	{
		if(!full())
		{
			_arr[++_top] = val;
		}
		else{
			cout << "Stack is full" << endl;
		}
	}
	void pop()
	{
		if(!empty())
		{
			_top--;
		}
		else{
			cout << "Stack is empty" << endl;
		}
	}

	int top()const
	{
		return _arr[_top];
	}

private:
	int _top;
	int _size;
	int * _arr;
};

int main(void)
{
	Stack st(10);
	cout << "Is Stack empty?" << st.empty() << endl;

	st.push(1);
	cout << "Is Stack empty?" << st.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		st.push(idx);
	}
	cout << "Is Stack empty?" << st.empty() << endl;

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	st.push(12);
	cout << "the top of the Stack is " << st.top() << endl;

	return 0;
}
