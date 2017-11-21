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

#if 0
	//系统提供的复制运算符=重载函数  已经能够满足需要
	Point & operator=(const Point & rhs)
	{
		_ix = rhs._ix;
		_iy = rhs._iy;
		return *this;
	}
#endif

	//this 是一个隐含的参数，this指向当前对象本身
	void print(/*const Point * this */)
	{
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")";
	}
private:
	int _ix;
	int _iy;
};

class Line
{
private:
	Point _pt1;
	Point _pt2;
public:
	Line(int x1, int y1, int x2, int y2)
	:_pt1(x1,y1) //对象成员的初始化也应该放在初始化列表中进行
	,_pt2(x2,y2)//调用对象成员自身的构造函数初始化
	{
		cout << "Line(int, int, int, int)" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << "-->";
		_pt2.print();
		cout << endl;
	}
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

int main(void)
{
	//test();
	Line l(1,2,3,4);
	l.printLine();

	return 0;
}
