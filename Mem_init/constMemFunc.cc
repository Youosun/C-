#include <iostream>
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


#if 1
	void print()
	{
		cout << "(" << this->_ix
		 	 << "," << this->_iy
			 << " )" << endl;
	}
#endif

#if 1
	void print(/*const Point * this*/) const
	{
		cout << "Point::print() const" << endl;
		cout << "(" << this->_ix
		 	 << "," << this->_iy
			 << " )" << endl;
	}
#endif
private:
	const int _ix;//const数据成员只能在初始化列表中初始化
	const int _iy;
};

int main(void)
{
	const Point p(1,2);//const对象只能调用const版本的成员函数
	p.print();


	Point p1(3,4); // 非const对象可以调用const成员函数
	p1.print();
	//如果两个版本的成员函数同时出现  则各调各的

	return 0;
}
