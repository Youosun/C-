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
	void display() const
	{ cout << "A::display() " << endl;}

	~A()
	{
		cout << "~A()" << endl;
	}
};

class B
{
public:
	void print() const
	{ cout << "B::print() " << endl;}
	~B()
	{
		cout << "~B()" << endl;
	}
};

class C 
: public A
, public B
{
public:
	void show() const
	{	cout << "C::show()" << endl;}
	~C()
	{
		cout << "~C()" << endl;
	}
};

int main(void)
{
	C c;
	c.display();
	c.print();
	c.show(); //多继承派生类别析构顺序

	return 0;
}
