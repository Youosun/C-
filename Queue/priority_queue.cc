#include <math.h>

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void test0()
{
	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};

//	priority_queue<int> pque(arr, arr + 10);
//	1. 默认情况下，按照std::less进行比较   但元素出队时是降序排列
//	2. 优先队列的底层实现是堆排序
//	3. 每一次比较时，拿堆顶元素与新元素进行比较， 满足条件时 用新元素替换到堆顶元素；
//		不满足条件时  将新元素插入堆中，并进行堆调整
	priority_queue<int> pque;

	for(int idx = 0; idx != 10; ++idx)
	{
		pque.push(arr[idx]);
		cout << "the top priority element = " << pque.top() << endl;
	}

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

void test1()
{
	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};

	priority_queue<int, vector<int>, std::greater<int> > pque;  //优先队列指定排序规则的同时  也需要指定底层采用的容器类型

	for(int idx = 0; idx != 10; ++idx)
	{
		pque.push(arr[idx]);
		cout << "the top priority element = " << pque.top() << endl;
	}

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{}

	friend std::ostream & operator<<(std::ostream & os, const Point &rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);

	float distance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point &rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
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

void test2()
{
	priority_queue<Point> pque;

	pque.push(Point(1, 2));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(3, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(-1, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(5, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(0, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

void test3()
{
	priority_queue<Point, vector<Point>, std::greater<Point> > pque;

	pque.push(Point(1, 2));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(3, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(-1, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(5, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(0, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
	}
}

struct Compare
{
	 bool operator()(const Point & lhs, const Point & rhs) const
	 {
		return lhs.distance() < rhs.distance();
	 }
};

void test4()
{
	priority_queue<Point, vector<Point>, Compare > pque;

	pque.push(Point(1, 2));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(3, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(-1, 4));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(5, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;
	pque.push(Point(0, 6));	
	cout << "当前队列中优先级最高的是:" << pque.top() << endl;

	while(!pque.empty())
	{
		cout << pque.top() << endl;
		pque.pop();
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
