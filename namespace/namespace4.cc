#include <iostream>
#include <stdio.h>//C头文件里面的所有实体都认为是放在匿名空间当中

using std::cout;//using声明机制
using std::endl;

int num = 1000;//匿名的命名空间

void test()
{
	cout << "test()" << endl;
}

namespace A
{
	int num = 10;
	void displayA()
	{
		cout << " displayA()" << endl;
	}
}//end of namespace A

namespace B
{
	int num = 100;
	void displayB(int num)
	{
		cout << "形参num:" << num << endl;//屏蔽了匿名空间中的num
		cout <<"A::num : " << A::num << endl;
		cout <<"B::num : " << B::num << endl;
		cout << "全局变量num:" << ::num << endl;
	}
}//end of namespace B

int test0()
{
	using A::displayA;
	using B::displayB;

	displayA();
	displayB(3);

	return 0;
}

int main(void)
{
	test0();

	::test();

	::printf("hello world\n");
	printf("C++\n");

	return 0;
}
