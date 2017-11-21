#include <iostream>

using namespace std;

//C++支持函数重载
//实现原理：名字改编(name mangling)
//nm foo.o查看
//步骤：当函数名字相同时，根据函数参数的类型、个数、顺序进行改编
int add(int x,int y)
{
	return x + y;
}

int add(int x,int y,int z)
{
	return x + y + z;
}

double add(double x, double y, double z)
{
	return x + y + z;
}

int add(double x, int y, char z)
{
	return 1;
}

int add(int x, double y, char z)
{
	return 2;
}

int main(void)
{
	int a = 3, b = 4, c = 5;
	
	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "add(a, b, c) = " << add(a, b, c) << endl;

	return 0;
}
