#include <iostream>
#include <string.h>
using namespace std;

struct A   //默认访问权限是public   
{
	void setA(int a)
	{
		_ia = a;
	}
	void print()
	{
		cout << "A::_ia = " << _ia << endl;
	}
	int _ia;
};


class Computer //默认的访问权限是private
{
private: //表现的是封装的特性
	char _brand[20];
	float _fprice;
public: //表示类的接口 --- 对外提供的服务
	void print();//函数也可以在类的内部实现---inline函数
	void setBrand(const char *);
	void setPrice(float);
};

void Computer::print()
{
	cout << "Brand = " << _brand << endl;
	cout << "Price = " << _fprice << endl;
}

void Computer::setBrand(const char * brand)
{
	strcpy(_brand,brand);
}

void Computer::setPrice(float fprice)
{
	_fprice	= fprice;
}


int main(void)
{
	Computer c1;
	//c1.print();  //未初始化  不能使用
	
	c1.setBrand("HASEE");
	c1.setPrice(3500);

	c1.print();

	A a;
	a.setA(3);
	a.print();

	return 0;
}
