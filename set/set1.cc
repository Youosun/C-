#include <math.h>
#include <iostream>
#include <set>
using namespace std;

void test0()
{
	int arr[] = {2, 1, 3, 5, 4, 6, 3, 5, 6, 7};
	//1.set内部不能存放相同的关键字，内部元素具有唯一性
	//2.默认情况下采用升序的方式进行排列
	set<int> setInt(arr, arr + 10);

	set<int>::const_iterator cit;
	for(cit = setInt.cbegin(); cit != setInt.cend(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;

//	cout << setInt[2] << endl; //set不支持随机访问 []运算符操作
}

void test1()
{
	int arr[] = {2, 1, 3, 5, 4, 6, 3, 5, 6, 7};
	set<int, std::greater<int> > setInt(arr, arr + 10);

	set<int>::const_iterator it;
	for(it = setInt.begin(); it != setInt.end(); ++it)
	{
		//*it = 7; //无论返回的迭代器类型是否具有const关键字  set均不允许修改元素的值
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

//内容相同，就认为这两个对象相等
#if 0
bool operator==(const Point & lhs, const Point & rhs)
{
	return (lhs._ix == rhs._ix && lhs._iy == rhs._iy);
}
#endif

struct Compare
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		cout << "Compare()" << endl;
		return lhs.distance() < rhs.distance();
	}
};

void test2()
{
	//set是如何判断两个元素相等的?
	//
	//1. 比较时用的是std::less<Point>, 也就是重载的 < 符号
	//2. 等价概念：!(e1 < e2) && !(e2 < e1)  两者互相不小于(根据具体的Compare策略)就认为两者等价相等 
	set<Point> points{
		Point(-1, 2),
		Point(3, 4),
		Point(0, -1),
		Point(1, 2), //所以这里set认为(-1,2) 与 (1,2) 等价 --- distance() 相同
		Point(5, 3),
		Point(1, 2)
	};

	set<Point>::const_iterator it;
	for(it = points.begin(); it != points.end(); ++it)
	{
		cout << *it << endl;
	}
}

void test3()
{
	set<Point, std::greater<Point> > points{ //利用greater进行比较自定义类类型  需要重载 > 操作符
		Point(-1, 2),
		Point(3, 4),
		Point(0, -1),
		Point(1, 2),
		Point(5, 3),
		Point(1, 2)
	};

	set<Point>::const_iterator it;
	for(it = points.begin(); it != points.end(); ++it)
	{
		cout << *it << endl;
	}
}

void test4()
{
	set<Point, Compare> points{ //使用自定义的functor比较自定义类类型  需要自定义函数对象Compare
		Point(-1, 2),			//这里会多次调用compare()进行比较
		Point(3, 4),
		Point(0, -1),
		Point(1, 2),
		Point(5, 3),
		Point(1, 2)
	};
	set<Point>::const_iterator it;
	for(it = points.begin(); it != points.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main(void)
{
//	test0();
//	test1();
//	test2();
//	test3();
	test4();

	return 0;
}
