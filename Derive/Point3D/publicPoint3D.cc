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

	void print()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" <<endl;
	}
private:
	int _ix;
	int _iy;
};

class Point3D
: public Point //接口继承
	//基类中的访问权限在派生类中得到完全继承
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display()const
	{
		print();  //在派生类内部可以调用print()函数
		cout << "_iz = " << _iz << endl;
	}
private:
	int _iz;
};

int main(void)
{
	Point3D p1(1, 2, 3);
	p1.display();
//	p1.print();  //error  基类的print()在Point3D派生类中变成private成员

	return 0;
}
