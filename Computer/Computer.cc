#include <iostream>
#include <string.h>
using namespace std;

class Computer
{
private:
	char * _brand;
	float _fprice;
public:
	Computer(const char * brand, float fprice);

	Computer();

	~Computer();

	Computer(const Computer & rhs);

	Computer & operator=(const Computer & rhs);

	void print();
};

Computer::Computer()
: _brand(new char[1]())
, _fprice(0.0)
{
	cout << "Computer()" << endl;
}

Computer::Computer(const char * brand, float fprice)
:_brand(new char[strlen(brand)+1]())
,_fprice(fprice)
{
	strcpy(_brand,brand);
	cout << "Computer(const char*,float)" << endl;
}

Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer" << endl;
}

Computer::Computer(const Computer & rhs)
:_brand(new char[strlen(rhs._brand)+1]())//深拷贝
,_fprice(rhs._fprice)
{
	strcpy(_brand,rhs._brand);
	cout << "Computer(const Computer&)" << endl;
}

Computer & Computer::operator=(const Computer & rhs)
{
	if(this != &rhs)  //1.考虑自拷贝情况
	{
		delete [] _brand; //2.先回收左操作数的空间
		_brand = new char[strlen(rhs._brand)+1]();//3.再进行深拷贝
		strcpy(_brand,rhs._brand);
		_fprice = rhs._fprice;
	}
	return *this;
}

void Computer::print()
{
	cout << "brand = " << _brand << endl;
	cout << "price = " << _fprice << endl;
}

int main(void)
{
	Computer c1("Lenovo",5000);

	cout << "c1 = ";
	c1.print();

	Computer c2;
	c2 = c1;
	cout << "-----" << endl;
	c2.print();

	Computer c3("Mac",10000);
	cout << "c3 = ";
	c3.print();

	c1 = c3;
	cout << "c1 =";
	c1.print();
	cout << "-----" << endl;

	c1 = c1;
	cout << "c1 = ";
	c1.print();

	return 0;
}
