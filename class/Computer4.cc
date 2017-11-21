#include <iostream>
#include <string.h>

using namespace std;

class Computer
{
public:
	Computer(const char * brand, float fprice);
	
	~Computer();

	Computer(const Computer & rhs);

	void print();
private:
	char * _brand;
	float _fprice;
};

#if 0
//系统提供的拷贝构造函数不再满足需要
Computer::Computer(const Computer & rhs)
:_brand(rhs._brand)
,_fprice(rhs._fprice)
{
	cout << "Computer(const Computer &)" << endl;
}
#endif

Computer::Computer(const char * brand, float fprice)
:_brand(new char[strlen(brand)+1]())
,_fprice(fprice)
{
	cout << " Computer(const char* ,int)" << endl;
	strcpy(_brand,brand);
}

Computer::Computer(const Computer & rhs)
:_brand(new char[strlen(rhs._brand)+1]())//进行深拷贝
,_fprice(rhs._fprice)
{
	cout << "Computer(const Computer &)" << endl;
	strcpy(_brand,rhs._brand);
}

Computer::~Computer()
{
	delete [] _brand; //析构函数作用：做清理工作
	cout << "~Computer()" << endl;
}

void Computer::print()
{
	cout << "brand = " << _brand << endl;
	cout << "price = " << _fprice << endl;
}

int main(void)
{
	Computer c1("Lenovo",5000);
	c1.print();

	Computer c3(c1);//执行拷贝构造函数
	c3.print();

	Computer c2 = c1;//执行拷贝构造函数
	c2.print();

	return 0;
}
