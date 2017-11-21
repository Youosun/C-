#include <iostream>
using namespace std;

class A
{
public:
	virtual
	void func(int x)
	{
		cout << "A::func(int)" << x << endl;
	}	
};

class B
: public A
{
public:
	void func(const char * s)
	{
		cout << "B::func(const char *)" << s << endl;
	}

	virtual void func(int x)
	{
		cout << "B::func(int)" << x << endl;
	}
};

int main(void)
{
	B b;

	b.func(10);  //使用对象进行函数调用  发生的是隐藏 oversee
				//	oversee隐藏只要求同名函数  就会发生
	b.func("hello");

	A * p = new B; //注意指针的类型
	p->func(0);  //使用基类类型的指针进行调用  发生的是覆盖 override
				// 重写/覆盖  要求函数同名且参数列表 返回值类型均相同
	p->func("China");//error 
//通过基类类型的指针  无法调用派生类自己的虚函数

	return 0;
}

