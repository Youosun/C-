#include "add.h"
#include <iostream>
using namespace std;

int main(void)
{
	int ia = 1, ib = 2;
	double da = 2.1, db = 3.4;
	char ca = 'a', cb = 1;

	cout << "add<int> = " << add(ia, ib) << endl;
	cout << "add<double> = " << add(da, db) << endl;
	cout << "add<char> = " << add(ca, cb) << endl;

	return 0;
}
