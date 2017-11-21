#include <iostream>
#include <memory>
using namespace std;

class Point
: public std::enable_shared_from_this<Point>
	//在类内部获取本对象this的shared_ptr的方式
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
#if 0
	Point * addPoint(const Point * p)
	{
		_ix += p->_ix;
		_iy += p->_iy;
		return this;
	}
#endif
#if 0
	shared_ptr<Point> addPoint(const Point * p)
	{
		_ix += p->_ix;
		_iy += p->_iy;
		return shared_ptr<Point>(this);
		//这里还是将this指针进行了智能指针的托管
		//调用函数接收该智能指针时  还是造成了同一this指针被两个智能指针托管
	}
#endif

	shared_ptr<Point> addPoint(Point * p)
	{
		_ix += p->_ix;
		_iy += p->_iy;
		return shared_from_this();
		//需要该类公有继承std::shared_from_this<Point>类型
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

int test0()
{//误用1:同时将一个原生裸指针交给不同的智能指针进行托管  造成double free问题
	Point * p1 = new Point(1, 2);
	shared_ptr<Point> sp1(p1);
	shared_ptr<Point> sp2(p1);
	unique_ptr<Point> upp(p1);

	return 0;
}

int test1()
{//误用2
	Point * p1 = new Point(1, 2);
	shared_ptr<Point> sp1(p1);
	shared_ptr<Point> sp2(new Point(3, 4));

	sp2.reset(sp1.get());  //在这里Point(3, 4)被析构
	cout << "*sp2 = " << *sp2 << endl;//sp2与sp1同时托管了同一个原生裸指针p1
	cout << "*sp1's use_count = " << sp1.use_count() << endl;
	//同样会造成同一对象析构两次的问题
	cout << "*sp2's use_count = " << sp2.use_count() << endl;
	return 0;
}

int test2()
{//误用3: 函数的返回值是一个原生裸指针
	shared_ptr<Point> sp1(new Point(1, 2));
	shared_ptr<Point> sp2(new Point(3, 4));

	shared_ptr<Point> sp3(sp1->addPoint(sp2.get()));
	//当addPoint()返回的是类型是Point *时, 
	//同样会使得原来的Point(1, 2)对象的指针被同时两个智能指针托管 只不过通过该函数指针指向的值发生了改变
	//造成同一对象析构两次的问题

	cout << "*sp1 = " << *sp1 << endl;
	return 0;
}

int main(void)
{
//	test0();
//	test1();
	test2();

	return 0;
}
