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

unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(88));
	return upi;
}


int main(void)
{
	std::unique_ptr<int> upi(new int(66));
	cout << "*upi = " << *upi << endl;

	unique_ptr<Point> pt(new Point(1, 2));
	cout << "*pt = " << *pt << endl;

//	unique_ptr<Point> pt2 = pt; //不能进行复制运算符操作 
//    unique_ptr<T> unique_ptr<T>(const T&) = delete;	
	std::unique_ptr<Point> pt3(new Point(3, 4));
	cout << "*pt3 = " << *pt3 << endl;
//	pt3 = pt;// 也不能进行复制拷贝函数
//	  unique_ptr<T> operator=(const T &) = delete;

	unique_ptr<int> upi2 = getValue(); //移动语义,getvalue()的返回值是临时变量  右值	
	cout << "*upi2 = " << *upi2 << endl;

	vector<unique_ptr<int> > vec;
//	vec.push_back(upi2); //vector添加元素时 都是将其拷贝一份到容器中  实际变量值与拷贝变量值是相互独立的

	//unique_ptr 对象  可以作为容器的元素
	vec.push_back(std::move(upi2));//所以要使用移动语义方式添加元素
									//添加完成之后  upi2不再使用
	//访问元素
	cout << *vec[0] << endl;
	//cout << "*upi2 = " << *upi2 << endl;

	return 0;
}
