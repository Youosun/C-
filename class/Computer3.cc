#include <iostream>
#include <string.h>

using namespace std;

class Computer
{
public:
	Computer(const char * brand,float fprice);
	~Computer();

	void print();
private:
	char * _brand;
	float _fprice;
};

Computer::Computer(const char * brand,float fprice)
:_brand(new char[strlen(brand)+1]() )
,_fprice(fprice)
{
	cout << "Computer(const char*,float)" << endl;
	strcpy(_brand,brand);//深拷贝
}

Computer::~Computer()
{
	delete [] _brand;
	cout << "~Computer()" << endl;
}

void Computer::print()
{
	cout << "brand: " << _brand << endl;
	cout << "price: " << _fprice << endl;
}

Computer pc2("HP",7000);

int main(void)
{
	Computer c1("Lenovo",5000); //对于栈对象来说，生命周期结束时自动调用析构函数释放空间
	c1.print();
	//c1.~Computer();
	cout << "-------" << endl;

	Computer * pc2 = new Computer("Mac",10000);  //堆对象
	pc2->print();

	delete pc2;//delete对象不可少

	return 0;
}
