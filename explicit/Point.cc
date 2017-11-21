#include <iostream>

using namespace std;

class Point
{
public:
	//explicit   通过explicit禁止隐式转换
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int ,int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point p1 = 1;  //存在隐式转换 
	p1.print();

	return 0;
}
