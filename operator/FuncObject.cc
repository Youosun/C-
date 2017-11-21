#include <iostream>
using namespace std;

class Demo
{
public:
	//函数调用运算符的重载只能以成员函数的形式重载
	int operator()(int x, int y)
	{
		return x > y ? x : y;
	}

	int operator()(int x, int y, int z)
	{
		return x > y ? (x > z ? x : z) : (y > z ? y : z);
	}
};

int main(void)
{
	Demo d;
	cout << "max = " << d(1, 2) << endl; //函数对象，重载了函数调用运算符的类创建的对象

	cout << "max = " << d(1, 2, 3) << endl;

	return 0;
}
