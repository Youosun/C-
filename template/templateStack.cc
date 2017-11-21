#include <iostream>
#include <string>
using namespace std;

template <typename T, int kSize = 10> //这里表示自定义的类模板自带两个参数T 和 kSize
class Stack
{
public:
	Stack()
	: _top(-1)
	, _arr(new T[kSize]())//初始化时  需要类型T提供无参的构造函数进行初始化
	{}

	~Stack();

	bool empty()const;
	bool full()const;
	void push(const T & value);
	void pop();
	T top()const;
private:
	int _top;
	T * _arr;
};

template <typename T, int kSize>
Stack<T, kSize>::~Stack()
{
	delete [] _arr;
}

template <typename T, int kSize>
bool Stack<T, kSize>::empty() const
{
	return _top == -1;
}

template <typename T, int kSize>
bool Stack<T, kSize>::full() const
{
	return _top == kSize - 1;
}

template <typename T, int kSize>
void Stack<T, kSize>::push(const T & value)
{
	if(!full())
	{
		_arr[++_top] = value;  //此处需要类型T 提供复制运算符函数  和 复制构造函数
	}else{
		cout << "栈已满" << endl;
	}
}

template <typename T, int kSize>
void Stack<T, kSize>::pop()
{
	if(!empty())
	{
		--_top;
	}else{
		cout << "栈已空" << endl;
	}
}

template <typename T, int kSize>
T Stack<T, kSize>::top() const
{
	return _arr[_top];
}

//----------------------自定义类型 X
//
class X
{
public:
	X()
	: _ix(0)
	{}

	X(int ix)
	: _ix(ix)
	{}

	friend std::ostream & operator<<(std::ostream & os, const X & rhs);
private:
	int _ix;
};

std::ostream & operator<<(std::ostream & os, const X & rhs)
{
	os << rhs._ix;
	return os;
}

void test0() //栈中存放的是内置类型int 
{
	Stack<int> st;
	cout << "此时栈是否为空?" << st.empty() << endl;
	st.push(1);
	cout << "此时栈是否为空?" << st.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		st.push(idx);
	}
	cout << "此时栈是否已满?" << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	cout << "此时栈是否为空?" << st.empty() << endl;
}

void test1() //栈中存放的是string类型
{
	Stack<string> st;
	cout << "此时栈是否为空?" << st.empty() << endl;
	st.push("AAAA");
	cout << "此时栈是否为空?" << st.empty() << endl;

	for(int idx = 1; idx != 11; ++idx)
	{
		string tmp(4, 'A' + idx);
		st.push(tmp);
	}
	cout << "此时栈是否已满?" << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout << endl;
	cout << "此时栈是否为空?" << st.empty() << endl;

}

int main(void)
{
//	test0();
//	test1();
	Stack<X> st; //栈中存放的是自定义类类型X 
				//此处的初始化需要X提供无参的构造函数
	cout << "此时栈是否为空?" << st.empty() << endl;

	st.push(X(1));
	cout << "此时栈是否为空?" << st.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		st.push(X(idx));
	}
	cout << "此时栈是否已满?" << st.full() << endl;

	while(!st.empty())
	{
		cout << st.top() << " ";//此处的输出需要X提供重载的输出流运算符
		st.pop();
	}
	cout << endl;
	cout << "此时栈是否为空?" << st.empty() << endl;

	return 0;
}
