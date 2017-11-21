#include <math.h>
#include <iostream>
#include <set>
using namespace std;

void test0()
{
	int arr[] = {2, 1, 3, 5, 4, 6, 3, 5, 6, 7};
	//1.multiset内部能够存放相同关键字，内部元素可以重复
	//2.默认情况下采用升序方式进行排列
	multiset<int> multisetInt(arr, arr + 10);
	
	multiset<int>::const_iterator it;
	for(it = multisetInt.begin(); it != multisetInt.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

//	cout << multisetInt[2] << endl;  //multiset同样不支持随机访问 [] 下标访问运算符
}

void test1()
{
	int arr[] = {2, 1, 3, 5, 4, 6, 3, 5, 6, 7};
	multiset<int, std::greater<int> > multisetInt(arr, arr + 10); //降序排列
	
	multiset<int>::const_iterator it;
	for(it = multisetInt.begin(); it != multisetInt.end(); ++it)
	{
		//*it = 7;//同样multiset也不支持对元素进行修改
		cout << *it << " ";
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);

	//friend bool operator==(const Point & lhs, const Point & rhs);
	
	float distance() const
	{
		return sqrt( _ix * _ix + _iy * _iy);
	}
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   <<")";

	return os;
}

bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.distance() < rhs.distance();
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.distance() > rhs.distance();
}

void test3()
{
	multiset<Point, std::greater<Point> > points{
		Point(-1, 2),
		Point(3, 4),
		Point(0, -1),
		Point(1, 2),
		Point(5, 3),
		Point(1, 2)
	};

	multiset<Point>::const_iterator it;
	for(it = points.begin(); it != points.end(); ++it)
	{
		cout << *it << endl;
	}
}

void test4()
{
	multiset<Point> points{
		Point(-1, 2),
		Point(3, 4),
		Point(0, -1),
		Point(1, 2),
		Point(5, 3),
		Point(1, 2)
	};

	multiset<Point>::const_iterator it;
	for(it = points.begin(); it != points.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main(void)
{
//	test0();
//	test1();
//	test3();
	test4();

	return 0;
}
