#include <iostream>

using namespace std;

//C++名字改编---函数重载的原理   nm + foo.o  查看编译后的函数名
//希望某个函数不进行c++的名字改编，按照C的方式进行调用
//
//实现C++与C的混合编程，C++兼容C的代码
#ifdef __cplusplus
extern "C"
{
#endif
int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}//end of extern "C"
#endif

int add(int x, int y, int z)
{
	return x + y + z;
}

int main(void)
{
	int a = 3, b = 4;
	cout << "add(a, b) = " << add(a,b) << endl;

	return 0;
}
