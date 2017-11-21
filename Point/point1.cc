#include <iostream>
using namespace std;

class Point
{
public:
#if 0
	//构造函数是能够进行重载的
	Point()
	: _ix(0)
	, _iy(0) //这里才是真正的初始化过程 ---> 初始化表达式  初始化列表
	{
		_ix = 0;//本质上是赋值语句，并不是初始化过程
		_iy = 0;//
		cout << "Point()" << endl;
	}

	Point(int ix)
	{
		_ix = ix;
		_iy = 0;
		cout << "Point(int)" << endl;
	}
#endif
//在类的内部如果显式定义了一个有参构造函数，系统就不会在提供默认的构造函数
//此时若还是希望能够调用默认构造函数创建对象，就必须显式定义默认构造函数
	Point(int ix = 0, int iy = 0)
	{
		_ix = ix;
		_iy = iy;
		cout << "Point(int,int)" << endl;
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


int main(void)
{
	Point pt;
	pt.print();

	Point pt2(1 ,2);
	pt2.print();

	Point pt3(3);
	pt3.print();

	return 0;
}
