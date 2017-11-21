 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-10 11:38:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A(int ix)
	: _ix(ix)
	{
		cout << "A(int)" << endl;
	}
	void display() const
	{ cout << "A::display() " << endl;}
private:
	int _ix;
};

class B
{
public:
	B(int iy)
	: _iy(iy)
	{
		cout << "B(int)" << endl;
	}
	void print() const
	{ cout << "B::print() " << endl;}
private:
	int _iy;
};

class C 
: public A
, public B
{
public:
	C(int ix, int iy, int iz)
	: B(iy)
	, A(ix)
	, _iz(iz)
	{
		cout << "C(int,int,int)" << endl;
	}

	void show() const
	{	cout << "C::show()" << endl;}
private:
	int _iz;
};

int main(void)
{
	C c(1, 2, 3);
	return 0;
}
