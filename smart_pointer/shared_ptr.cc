#include <iostream>
#include <vector>
#include <memory>
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

	~Point()
	{
		cout << "~Point()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
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

int main(void)
{
	std::shared_ptr<int> upi(new int(66));
	cout << "*upi = " << *upi << endl;

	shared_ptr<Point> pt(new Point(1, 2));
	cout << "*pt = " << *pt << endl;
	cout << "*pt's use_count = " << pt.use_count() << endl;

	shared_ptr<Point> pt3(new Point(3, 4));
	cout << "*pt3 = " << *pt3 << endl;

	shared_ptr<Point> pt2 = pt;

	cout << "pt's use_count = " << pt.use_count() << endl;
	cout << "pt2's use_count = " << pt2.use_count() << endl;
	pt3 = pt;
	cout << "pt2's use_count = " << pt2.use_count() << endl;
	cout << "pt3's use_count = " << pt3.use_count() << endl; 
	//shared_ptr当use_count不为1时,析构对象只是在对应的智能指针上减一
	//直到最后才调用析构函数  析构变量  回收空间
	cout << endl;
	
	shared_ptr<Point> pt4(new Point(1, 2)); 
	//编译器并不是通过检查智能指针指向变量的值是否相同进行引用计数的变化
	//而是通过表面上该指针 被其他变量拷贝的个数来增减引用计数
	cout << "pt4's use_count = " << pt4.use_count() << endl; // 1

	return 0;
}
