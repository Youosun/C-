#include <iostream>
using namespace std;

class A
{
public:
	A(int ix = 0)
	: _ix(ix)
	{
		cout << "A(int)" << endl;
	}

	void print()const
	{
		cout << "A::_ix = " << _ix << endl;
	}

	void print(int ix)const
	{
		cout << "ix = " << ix << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _ix;
};

class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

	B(int iz)
	: _iz(iz)
	{
		cout << "B(int)" << endl;
	}

	void print()const
	{
		cout << "B::_iz = " << _iz << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _iz;
};

class C
: public A
{
public:
	C(int ix, int iy, int iz)
	: A(ix)
	, _iy(iy)
	, _b(iz)
	{
		cout << "C(int,int,int)" << endl;
	}
//隐藏机制:
//当派生类定义了与基类同名的函数时,基类的同名函数被隐藏
//	即使基类同名成员函数参数不同时也会被隐藏
	void print()const
	{
		cout << "C:: _iy = " << _iy << endl;
	}

	void display()const
	{
		print();  //此处调用的是C::print()
		_b.print();
		cout << "C::iy = " << _iy << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}
private:
	int _iy;
	B _b;
};

int main(void)
{
	C c(1, 2, 3);
	c.print();
	//c.print(12);  error  说明基类A中带参数的同名print()函数也被隐藏
	c.display();  //diaplay()中调用的A的print()函数被隐藏

	c.A::print();
	//被隐藏的基类成员函数可以通过  类名::func()方式进行显式调用

	return 0;
}
