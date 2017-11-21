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
	void print() const
	{ cout << "A::display() " << endl;}
};

class B
{
public:
	void print() const
	{ cout << "B::print() " << endl;}
};

class C 
: public A
, public B
{
public:
	void show() const
	{	cout << "C::show()" << endl;}
private:
	int _iz;
};

int main(void)
{
	C c;
	//c.print(); //成员名冲突的二义性
	c.A::print(); //解决:作用域限定符
	c.B::print();
	c.show();

	return 0;
}
