#include <iostream>

using std::cout;
using std::endl;

void test()
{
	cout << "test() " << endl;
}

namespace B //同一个namespace可以分开来写  但注意要在namespace结束时显式声明结束位置
{
	int num = 3;
}

namespace A
{
	int num = 10;
	void displayA()
	{
		cout << "displayA()" << endl;
		cout << "B::num = " << B::num << endl;
	}
} //end of namespace A

namespace B
{
	void displayB()
	{
		cout << "displayB()" << endl;
		A::displayA();
	}
}//end of namespace B

int test0(void)
{
	using A::displayA;
	using B::displayB;

	displayB();
	
	return 0;
}

int main(void)
{
	test0();

	return 0;
}
