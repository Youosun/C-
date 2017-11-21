#include <iostream>
using namespace std;

#if 0
//值传递 ==> 本质：进行复制之后，实参与形参无关
void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}
#endif

//地址传递  ==>  本质：进行复制
void swap(int * x,int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//引用传递的好处：
//参数传递时，减少复制的开销，提高程序的执行效率
//使用更加直观
void swap(int & refa, int & refb)
{
	int temp = refa;
	refa = refb;
	refb = temp;
}

//引用作为返回值时也不会进行复制
//返回值的变量的周期一定要大于函数
