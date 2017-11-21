#include <iostream>
using std::cout;
using std::endl;

//指针数组  vs  数组指针
//指针函数   vs  函数指针
//int * func( )    int (*func)( )

int main(void)
{
	const int a=100; //const常量必须要进行初始化
	const int * pa = &a;


	int b=1;
	int c=10;

//	int & reff = 10;//非const的左值引用无法绑定右值
	const int & refff = 10; //const的左值引用可以绑定右值 字面值常量


	const int * pb = &a;//常量指针(pointer to const)  指向常量的指针  所以不能通过指针去修改常量的值
	pb = &b;  //但指针本身的值并不是常量   所以可以改变指针的指向----底层const  限定的是底层变量的常量特性

	int * const pc = &b;//指针常量(const pointer) 指针的值是常量  所以不能改变指针的指向
	*pc = 2;	//当指针指向的变量不一定是常量   根据指向的变量的限定类型-----顶层const  限定的是指针的值

	cout << "b = " << b << endl;
	const int * const pd = &c;//顶层与底层const   两者都不能修改
	//*pd = 1000;
	//*pd = &b;

	return 0;
}
