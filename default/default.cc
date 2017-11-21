#include <iostream>
using std::cout;
using std::endl;

//默认参数的设置只能采用从右到左的顺序
int add(int x = 1, int y = 0)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}

int main(void)
{
	int a = 3, b = 4;

	cout << add(a, b) << endl;
	cout << add(a) << endl;
	cout << add() << endl;

	return 0;
}
