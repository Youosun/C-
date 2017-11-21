#include <iostream>
using namespace std;

void test0()
{
	int a = 3;
	if(false && ++a)
	{
		cout << "a = " << a << endl;
	}
	cout << "a = " << a << endl;
}

void test1()
{
	int a = 3;
	if (true || ++a)
	{
		cout << "a = " << a << endl;
	}
	cout << "a = " << a << endl;
}

int main(void)
{
	test0();
	test1();

	return 0;
}
