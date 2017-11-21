#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
	//	_ix = ix;//这里实际上是赋值语句  违反了数据成员const的属性限定
	//	_iy = iy;
		cout << "Point(int,int)" << endl;
	}

	void print()
	{
		cout << "(" << this->_ix
		 	 << "," << this->_iy
			 << " )" << endl;
	}
private:
	const int _ix;//const数据成员只能在初始化列表中初始化
	const int _iy;
};

int main(void)
{
	Point p(1,2);
	p.print();

	return 0;
}
