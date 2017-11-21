#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	int getX()const
	{
		return _ix;
	}

	int getY()const
	{
		return _iy;
	}
private:
	int _ix;
	int _iy;
};

class Point3D
: public Point
{
public:
	Point3D(int ix = 0, int iy = 0, int iz = 0)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int, int, int)" << endl;
	}

	void display()const
	{
		print();
		cout << "_z = " << _iz << endl;
	}

#if 0
	Point3D & operator=(const Point & rhs)
	{
		if(this != &rhs)
		{
			Point::operator=(rhs);
			_iz = 0;
		}
		return *this;
	}
#endif

private:
	int _iz;
};

int main(void)
{
	Point p1(4, 5);
	p1.print();

	Point3D p2(1, 2, 3);
	p2.display();

	p1 = p2;  //Point & operator=(const Point & rhs);
			 //将派生类赋值给基类  默认调用了基类的赋值运算符函数
	p1.print();

	//p2 = p1; //Point3D & operator=(const Point & rhs);
//	将基类赋值给派生类调用派生类的赋值运算符函数   
//	需要显式定义转换函数 默认的赋值运算符函数不满足拷贝需要
	
	cout << endl;
	Point & ref = p1;
	ref.print();

	cout << endl;
	Point * p = &p1;
	p->print();
	return 0;
}
