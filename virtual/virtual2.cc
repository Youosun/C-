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
private:
	double _dx;  //存在内存对齐机制
};

class Sub
: public Base
{
public:
#if 1
//	virtual   //此处的virtual与否  只与下一继承关系类相关  与自身对象调用无关
	int func(int x)
	{
		cout << "Sub::func() x = " << x << endl;
		return 0;
	}
#endif

	virtual
	int func()
	{
		return 0;
	}

private:
	double _dy;
};

//动态多态(虚函数机制的实现)  被激活的条件
//1. 基类要定义一个虚函数
//2. 派生类要覆盖该基函数    //oversee覆盖  覆盖时要保证函数名  参数  返回值类型 保持一致  
//3. 基类的指针或者引用指向派生类对象
//4. 该指针或引用调用虚函数


void display(Base * pbase)
{
	pbase->func(10);
}

void print(Base & base)
{
	base.func(1);
}

void test0()
{
	Base * p = new Sub();
	p->func(2);

	Base base;
	Sub sub;
	display(&base);  //具体函数的调用并不是根据指针的类型进行判断
	display(&sub);  //而是根据指针所指变量的类型进行判断
}

void test1()
{
	Base base;
	Sub sub;
	print(base); //对于引用情况同上
	print(sub);
}

void printsize()
{
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(Base) = " << sizeof(Base) << endl;
	cout << "sizeof(Sub) = " << sizeof(Sub) << endl;
}

int main(void)
{
	test0()	;
	cout << "end1" << endl;
	test1();
	cout << "end2" << endl;
	printsize();
	return 0;
}
