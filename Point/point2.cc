#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	{
		_ix = ix;
		_iy = iy;
		cout << "Point(int,int)" << endl;
	}

	//系统自动提供了一个复制构造函数
	//
	//1、复制构造函数的参数引号不能去掉,去掉以后在调用复制构造函数时
	//会导致无穷递归，直到栈溢出
	//2、const关键字不能去掉，如果去掉，右值形式存在的Point对象无法进行传参

	Point(const Point & rhs) //const Point rhs = pt;
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy 
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};


int test(void)
{
	Point pt1(1,2);
	pt1.print();

	Point pt2;
	pt2 = pt1;
	pt2.print();

	Point pt3(3);
	pt3.print();

	return 0;
}

//函数的形参是对象,当形参与实参结合时，会调用拷贝构造函数
void func1(Point pt)
{
	pt.print();
}

//当函数的返回值时对象，也会调用拷贝构造函数 
//编译器优化选项-fno-elide-constructors
Point func2()
{
	Point p(1,2);
	p.print();
	return p;
}

int main(void)
{
//	test();

//	Point p1(1,2);
//	func1(p1);
	
	func2();
	return 0;
}
