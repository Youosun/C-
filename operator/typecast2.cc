#include <iostream>
using namespace std;

class AnotherPoint;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	//类型转换函数：由自定义类型向其他类型转换
	//1、类的成员函数形式
	//2、无返回值类型，但函数体内必须以传值的方式返回一个目标类型
	//3、无参数
	//4、能不使用就不使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix * _iy;
	}

	operator double()
	{
		return static_cast<double>(_ix) / _iy;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

	operator AnotherPoint();
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";

	return os;
}


class AnotherPoint
{
public:
	AnotherPoint(double ix, double iy)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os, const AnotherPoint & rhs);

	operator Point();
		
private:
	double _ix;
	double _iy;
};

std::ostream & operator<<(std::ostream & os,const AnotherPoint & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")" ;
	return os;
}

AnotherPoint::operator Point()
{
	return Point(_ix, _iy);
}

Point::operator AnotherPoint()
{
	return AnotherPoint(_ix, _iy);
}

int main(void)
{
	Point c1(1, 2);
//	cout << "int() = " << int(c1) << endl;
//
//	cout << "double = " << double(c1) << endl;

	cout << "AnotherPoint() = " << AnotherPoint(c1) << endl;

	AnotherPoint c2(1.1, 2.8);
	cout << "Point() = " << Point(c2) << endl;

	return 0;
}
