#include <iostream>

using namespace std;

int test()
{
	//_Bool c中内置的布尔类型
	if(-100)
	{

	}

	if(0)
	{
	}

	return 0;
}

int main(void)
{
	bool b1 = 100;
	bool b2 = -100;
	bool b3 = 0;
	bool b4 = true;
	bool b5 = false;

	cout << "b1 = " << b1 << endl;
	cout << "b2 = " << b2 << endl;
	cout << "b3 = " << b3 << endl;
	cout << "b4 = " << b4 << endl;
	cout << "b5 = " << b5 << endl;

	cout << "sizeof(bool) = " << sizeof(bool) << endl;

 
	return 0;
}
