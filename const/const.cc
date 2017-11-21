#include<iostream>
using std::cout;
using std::endl;

//宏定义与const关键字的差别

#define MAX 1024 //1、宏定义发生的时机是预处理阶段--》编译阶段--》链接阶段--》可执行程序
//仅仅只做了字符串的替换,不涉及类型的检查.
//有可能将错误发生的时机延后到运行时错误
//2.使用const关键字进行定义时，发生的时机就是编译时，具有类型检查功能
//尽量使用const关键字替换宏定义
int main(void)
{
	cout << MAX << endl;

	const int a = 100; //常量的值不能修改
	cout << "a = " << a << endl;

	return 0;
}
