#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	, _ref(_ix)
	{
	//	_ix = ix;
	//	_iy = iy;
		cout << "Point(int,int)" << endl;
	}

	void print()
	{
		cout << "(" << this->_ix
		 	 << "," << this->_iy
			 << "," << this->_ref
			 << ")" << endl;
	}
private:
	int _ix;//const数据成员只能在初始化列表中初始化
	int _iy;
	int & _ref;//引用数据成员也只能在初始化列表中初始化
				//注意初始化对象的生命周期
};

int main(void)
{
	Point p(1,2);
	p.print();

	return 0;
}
