#include <math.h>

#include <iostream>
using std::cout;
using std::endl;

class Point; //类的前置声明，声明的是一个不完全的类

class Line
{
public:
	float distance(const Point & pt1, const Point & pt2);	
};

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	//友元之他类的成员函数
	friend float Line::distance(const Point & pt1, const Point & pt2);
private:
	int _ix;
	int _iy;
};

float Line::distance(const Point & pt1, const Point & pt2)
{
	return sqrt((pt1._ix - pt2._ix) * (pt1._ix - pt2._ix) + (pt1._iy - pt2._iy) * (pt1._iy - pt2._iy));
}

int main(void)
{
	Point pt1(1, 2);
	Point pt2(2, 3);

	Line line;
	cout << "distance = " << line.distance(pt1, pt2) << endl;

	return 0;
}
