#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	{
		_ix = ix;
		_iy = iy;
		cout << "Point(int,int)" << endl;
	}

#if 1
	//系统提供的复制运算符=重载函数  已经能够满足需要
	Point & operator=(const Point & rhs)
	{
		_ix = rhs._ix;
		_iy = rhs._iy;
		return *this;
	}
#endif

	//this 是一个隐含的参数，this指向当前对象本身
	void print(/*const Point * this */)
	{
		cout << "(" << this->_ix
			 << "," << this->_iy 
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};


int test(void)
{
	Point p = 1;//这里存在隐式转换  可以使用explicit禁止隐式转换
	p.print();

	Point pt1(1,2);
	pt1.print();

	Point pt2;
	pt2 = pt1;
	pt2.print();

	Point pt3(3);
	pt3.print();

	return 0;
}

int main(void)
{
	test();

	return 0;
}
