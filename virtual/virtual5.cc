#include <iostream>
using namespace std;

//1. 在构造函数或析构函数中调用虚函数采用的是静态联编
//2. 构造函数为什么不能是虚函数?
//  根据虚函数的使用条件来说, 只有先创建对象,才有了虚函数指针,
//  然后才能通过他去调用虚函数

//oversee 隐藏  override 重写/覆盖  overload 重载
//
//oversee的使用条件最宽 派生类的函数屏蔽了基类中的同名函数
//1. 当函数的参数列表相同时
//		与override 重写/覆盖的区别在于  基类中的同名函数为虚函数
//2. 当函数的参数列表不同时
//		与overload 重载的区别在于  同名函数是否在同一个类中

class Base0
{
public:
	Base0()
	{
		cout << "Base0()" << endl;
	}

	virtual
	void func1()
	{
		cout << "Base0::func1()" << endl;
	}

	virtual
	void func2()
	{
		cout << "Base0::func2()" << endl;
	}

	~Base0()
	{
		cout << "~Base0()" << endl;
	}
};

class Base1
: public Base0
{
public:
	Base1()
	: Base0()
	{
		cout << "Base1() " << endl;
		func1();  //在构造函数或析构函数中调用虚函数采用的时静态联编
	}

#if 1
//	virtual
	void func1()  //隐藏该函数并不在乎是否是virtual函数
	{
		cout << "Base1::func1()" << endl;
	}
#endif

	virtual
	void func2()
	{
		cout << "Base1::func2() " << endl;
	}

	~Base1()
	{
		func2();
		cout << "~Base1()" << endl;
	}

};

class Sub
: public Base1
{
public:
	Sub()
	: Base1()
	{
		cout << "Sub()" << endl;
	}

	~Sub()
	{
		cout << "~Sub()" << endl;
	}

	virtual
	void func1()
	{
		cout << "Sub::func1()" << endl;
	}

	virtual
	void func2()
	{
		cout << "Sub::func2()" << endl;
	}
};

int main(void)
{
	Sub sub;

	return 0;
}
