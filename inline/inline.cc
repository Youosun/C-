#include <iostream>

#define MAX(a, b) (a) > (b) ? (a) : (b)


//在函数前面加上inline关键字后，在调用函数时
//会将函数体的内容直接进行替换  从而提高函数的执行效率
inline void print(void)  //声明内联函数 功能等价于带参数的宏定义
{
	std::cout << "hello world "<< std::endl;
}

int main(void)
{
	::print();

	return 0;
}
