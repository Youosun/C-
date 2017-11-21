#include <iostream>
using namespace std;

//智能指针的本质，利用栈对象作用域结束时 自动调用析构函数的特性 管理资源
template <typename T>
class RAII
{
public:
	RAII(T & p)
	: _p(&p)
	{
		cout << "RAII(T&)" << endl;
	}

	RAII(T && p)
	: _p(&p)
	{
		cout << "RAII(T &&)" << endl;
	}

	RAII(T * p)
	: _p(p)
	{
		cout << "RAII(T*)" << endl;
	}

	T & operator*()
	{
		if(_p)
			return *_p;
	}

	T * operator->()
	{
		return _p;
	}

	T * get()
	{
		return _p;
	}

	~RAII()
	{
		if(_p)
			delete _p;
	}
private:
	T * _p;
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	void print()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

void test0()
{
	int *p1 = new int(1);
	RAII<int> pInt(p1);

	cout << *p1 << endl;
	cout << *pInt << endl;
}

int main(void)
{
	test0();

	return 0;
}
