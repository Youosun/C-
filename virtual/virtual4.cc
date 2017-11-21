#include <iostream>
using namespace std;

class Base
{
public:
	virtual 
	int func(int x)
	{
		cout << "Base::func() x = " << x << endl;
		return 0;
	}

	void callBase1()
	{
		this->func(10); //动态多态
	}

	void callBase2()
	{
		Base::func(1);
	}	
private:
	double _dy;
};

class Sub
: public Base
{
public:
	int func(int x)
	{
		cout << "Sub::func(int) x = " << x << endl;
		return x;
	}

	virtual
	void func()
	{}

	void callSub1()
	{
		func(2);
	}
private:
	double _dy;

};

void printsize()
{
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Sub) = " << sizeof(Sub) << endl;
}

int main(void)
{
	Base base;
	Sub sub;

	Base * pbase = &base;
	pbase->callBase1();
	pbase->callBase2();
	cout << endl;

	pbase = &sub;
	pbase->callBase1(); //此处调用了Sub的func(int)函数
						//而callBase1()  为非虚函数 
						//转调用this(&Sub)的func(int) 虚函数
	pbase->callBase2();

	//pbase->callSub1(); pbase为基类指针  不能调用派生类非虚函数callSub1()
	//当调用非虚函数时  适应的情况在于指针的类型  而不是指针所指对象的类型
	printsize();

	return 0;
}
