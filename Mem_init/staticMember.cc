#include <iostream>
using namespace std;

class Computer
{
public:
	Computer(float fprice)
	:_fprice(fprice)
	{
		_totalPrice += _fprice; //注意在构造函数中操作静态的数据成员
								//以反映所有对象共享的静态变量的变化情况
	}

	void print()
	{
		cout << "totalPrice=" << _totalPrice << endl;
	}

	~Computer()
	{
		_totalPrice -= _fprice;  //注意在析构函数中操作静态的数据成员
								//反映销毁一个对象后对于全局的静态成员变量的影响
	}
private:
	float _fprice;
	static float _totalPrice;//静态数据成员由该类的所有成员共享  不属于特定的某个对象
};

//静态数据成员的初始化只能在类之外进行
float Computer::_totalPrice = 0.0;
//静态变量存储在全局区  所以应在全局的位置初始化
//
int main(void)
{
	Computer c1(2000);
	c1.print();
	{
		Computer c2(3000);
		c2.print();
	}
	Computer c3(4000);
	c3.print();

	return 0;
}
