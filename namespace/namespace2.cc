#include <iostream>
using std::cout;//using 声明机制 推荐
using std::endl;

using namespace std;// using编译指令

//作用域限定符
//
//匿名命名空间   ::memcopy
//				 ::strcpy
namespace A
{
	void testA()
	{
		cout << " funcA " << endl;
	}
}

namespace B
{
	const int a = 10;
	int b = 20;

	const int* pa = &a;//两个方式相同 //指针常量
	int const * pb = &a;

	int * const pc = &b;//常量指针
}

int main(void)
{
	A::testA();
	cout << "hello world" << endl;

	return 0;
}

