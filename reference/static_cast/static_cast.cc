#include <iostream>

using namespace std;

int test0(void)
{
	double d1 = 3.33;

	int ival = (int) d1;
	int ival2 = int(d1);

	cout << "ival = " << ival << endl;
	cout << "ival2 = " << ival2 << endl;

	return 0;
}

int main(void)
{
	double d1 = 3.33;
	int ival = static_cast<int>(d1);

	cout << "ival = " << ival << endl;

	//const_cast  dynamic_cast reinterpret_cast
	
	return 0;
}
