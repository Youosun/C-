#include <iostream>
#include <functional>
using namespace std;

//   int(int,int)  ---> 函数标签
//	typedef int (*function)(int, int); --> C语言函数指针类型
//	function<int(int, int)> f    ---> C++函数对象



int func(int x, int y)
{
	return x + y;
}

struct Foo
{
	int add(int x, int y) //非静态的成员函数第一个参数this 指针
	{
		return x + y;
	}
};

void test0()
{
	//bind 提前绑定参数时，未提前绑定的参数所在的位置需要使用占位符占住位置
	auto f1 = bind(func, 10, std::placeholders::_1); //占位符
	cout << f1(20) << endl;


	auto f2 = bind(func, 10 ,11);
	cout << f2() << endl;
}

void test1()
{
	typedef int (*Function)(int, int);
	Function f = func;//也是回调函数的注册
	cout << f(1, 2) << endl;
}

void test2()
{
	//这种函数的赋值形式 --> 回调函数的注册
	//function 可以看做函数类型的容器
	std::function<int(int)> f1 = bind(func, 10, std::placeholders::_1);
	cout << f1(20) << endl;

	Foo foo;
	//bind绑定类的成员函数， 要在前面加上取地址 &
	f1 = bind(&Foo::add, &foo, 10, std::placeholders::_1); //传递是实参时  传递地址值
	cout << f1(20) << endl;

	function<int()> f2 = bind(func, 10, 11);
	cout << f2() << endl;
}

void display(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}

void test3()
{
	using namespace std::placeholders;

	int n = 7;
	auto f1 = bind(display, _2, _1, 42, std::cref(n), n);
	//bind的占位符所在的位置代表的是形参的位置
	//占位符本身的数字  代表了实参传递时要绑定的位置
	//bind绑定参数时 采用的是值传递  会进行复制
	//	所以在绑定成员函数时，第一个参数尽量用对象的地址值传递
	f1(11, 22, 1001);
	//如果采用了auto关键字接受bind的返回值  调用f1时 理论上可以有很多的参数  多余的实参是无效参数
	//function<void(int,int)> f1 = bind(display, _2, _1, 42, std::cref(n), n);

}

int main(void)
{
//	test0();
	test3();
	return 0;
}
