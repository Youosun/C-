#include <iostream>
#include <string.h>
using namespace std;

class Computer
{
public:
	Computer(const char * brand, float fprice);

	~Computer();

	Computer(const Computer & rhs);

	Computer & operator=(const Computer & rhs);
	
	void print();

	//因为静态的成员函数不属于任何一个特定的对象
	//所以静态的成员函数参数中不含this指针
	//
	//所以在函数内部不能直接访问非静态的数据成员以及成员函数   全局---》局部 并不知道是哪一个
	//只能访问静态数据成员和静态成员函数
	static void printTotal()
	{
		//print();//error
		//cout << "brand = " << _brand << endl; //error
		cout << "totalPrice = " << _totalPrice << endl;
	}

	static void printComputer(const Computer & com)
	{
		cout << "brand =" << com._brand << endl;
		cout << "price = " << com._fprice << endl;
	}

private:
	char * _brand;
	float _fprice;
	static float _totalPrice;
};

float Computer::_totalPrice = 0.0;

Computer::Computer(const char * brand, float fprice)
: _brand(new char[strlen(brand)+1]())
, _fprice(fprice)
{
	strcpy(_brand,brand);
	cout << "Computer(const char*,float)" << endl;

	_totalPrice += _fprice;
}

Computer::Computer(const Computer & rhs)
: _brand(new char[strlen(rhs._brand)+1]())
, _fprice(rhs._fprice)
{
	strcpy(_brand,rhs._brand);
	cout << "Computer(const Computer&)" << endl;

	_totalPrice += _fprice;
}

Computer & Computer::operator=(const Computer & rhs)  //拷贝运算符执行的是拷贝任务  
{													// 除了清除左值对象中申请的空间外
	if(this != &rhs)								// 并不承担对象的构造和析构过程---即并没有创建和销毁对象
	{												//所以此处并不涉及对静态成员变量的改变
		delete [] _brand;
		_brand = new char[strlen(rhs._brand)+1]();
		strcpy(_brand,rhs._brand);
		_fprice = rhs._fprice;
	}
	return *this;
}

Computer::~Computer()
{
	_totalPrice -= _fprice;
	cout << "~Computer" << endl;
}

void Computer::print()
{
	cout << "brand = " << _brand << endl;
	cout << "price = " << _fprice <<endl;
}

int main(void)
{
	Computer c1("Lenovo",5000);

	Computer::printComputer(c1);
	Computer::printTotal();

	Computer c2("Mac",10000);
	Computer::printComputer(c2);
	Computer::printTotal();

	Computer c3 = c1;
	Computer::printComputer(c3);
	Computer::printTotal();

	Computer c4(c1);
	Computer::printComputer(c4);
	Computer::printTotal();

	return 0;
}
