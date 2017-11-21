#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	Base(int base)
	: _ibase(base)
	{
		cout << "Base(int)" << endl;
	}
private:
	int _ibase;
};

class Derived
: public Base
{
public:
#if 0
	Derived(int ix)
	: _ix(ix)
	{
		cout << "Derived(int)" << endl;
	}
#endif

	void print() const
	{
		cout << "Derived::_ix = " << _ix << endl;
	}
private:
	int _ix;
};

int main(void)
{
	Derived d1;  //调用派生类无参构造函数之前,先调用基类的无参构造函数
	d1.print();  //基类数据成员随机初始化

	return 0;
}
