#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	//类型转换函数：由自定义类型向其他类型转换
	//1、类的成员函数形式
	//2、无返回值类型，但函数体内必须以传值的方式返回一个目标类型
	//3、无参数
	//4、能不使用就不使用
	operator int()
	{
		cout << "operator int()" << endl;
		return _ix * _iy;
	}

	operator double()
	{
		return static_cast<double>(_ix) / _iy;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point c1(1, 2);
	cout << "int() = " << int(c1) << endl;

	cout << "double = " << double(c1) << endl;

	return 0;
}
