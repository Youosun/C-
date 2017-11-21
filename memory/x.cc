#include <iostream>
using namespace std;

class X
{
private:
	int _ix;
	int _iy;
public:
	X(int a)//数据成员初始化的顺序并不是由初始化列表当中的顺序决定的
	:_iy(a), _ix(_iy) //而是由数据成员在类中被声明的顺序决定的
	{
		cout << "X(int)" << endl;
	}
	
	void print()
	{
		cout << "_ix = " << _ix << endl
			<< "_iy = " << _iy << endl;
	}
};

int main(void)
{
	X x(3);
	x.print();

	return 0;
}

