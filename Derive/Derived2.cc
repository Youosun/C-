#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	: _ibase(0)
	{
		cout << "Base()" << endl;
	}

	Base(int base)
	: _ibase(base)
	{
		cout << "Base(int)" << endl;
	}

	void display()const
	{
		cout << "Base::_ibase = " << _ibase << endl;
	}
private:
	int _ibase;
};

//2.派生类没有显式定义构造函数时,创建派生类对象时,
//基类部分必须显式提供默认构造函数
class Derived
: public Base
{
public:
	Derived(int ix) //需要基类显式提供默认构造函数
	: Base()//当未提供基类的构造参数时,初始化列表中需显式调用基类的默认构造函数进行初始化
	, _ix(ix)
	{
		cout << "Derived(int) " << endl;
	}

	Derived(int ibase, int ix)
	: Base(ibase) //提供了基类的构造参数时,显式调用基类的有参构造函数进行初始化
	, _ix(ix)
	{
		cout << "Derived(int,int)" << endl;
	}

	void print()const
	{
		display();
		cout << "Derived::_ix = " << _ix << endl;
	}
private:
	int _ix;
};

int main(void)
{
	Derived d1(1);
	d1.print();

	Derived d2(3, 4);
	d2.print();

	return 0;
}
