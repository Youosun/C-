 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-26 14:34:35
 ///
 

#include <math.h>

#include <iostream>
using std::cout;
using std::endl;


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

	//友元之普通函数(自由函数)
	friend float distance(const Point & pt1, const Point & pt2);
private:
	int _ix;
	int _iy;
};


float distance(const Point & pt1, const Point & pt2)
{
	return sqrt((pt1._ix -pt2._ix) * (pt1._ix -pt2._ix) + 
				(pt1._iy -pt2._iy) * (pt1._iy -pt2._iy));
}

int main(void)
{
	Point pt1(1, 2);
	Point pt2(3, 4);

	cout << "两点之间的距离是: " << distance(pt1, pt2) << endl;
	return 0;
}
