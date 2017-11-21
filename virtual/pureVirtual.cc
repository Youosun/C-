#include <iostream>
using namespace std;

class A
{//拥有纯虚函数的类就是一个接口类
public:
	//拥有纯虚函数的类是抽象类,抽象类不能创建对象  但可以创建指针
	virtual void display()=0;
	virtual void print()=0;
};

class B
: public A
{//当派生类继承自抽象类, 必须实现基类所有的纯虚函数,才能够创建对象
//只要有一个纯虚函数没有实现  其依然是一个抽象类
public:
	void display()
	{
		cout << "B::display()" << endl;
	}
};

class C
: public B
{
public:
	void print()
	{
		cout << "C::print()" << endl; 
	}
};

int main(void)
{
//	A a;//error
//	A * p = new B;//error B仍然是一个抽象类
	A * p = new C;//抽象类不能够创建对象  但能够创建指针对象指向派生类
	p->display();
	p->print();
	
	cout << "sizeof(B) = " << sizeof(B) << endl;

	return 0;
}
