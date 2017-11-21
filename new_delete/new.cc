#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::endl;

//malloc  free    与new\delete的差别
//1、malloc/free 是c的标准库函数
//	 new/delete是C++的表达式
//
//2、malloc在开辟空间时，并不会对空间进行初始化
//	 new表达式在开辟空间时，是可以进行初始化

int main(void)
{
	int * p1 = (int*)malloc(sizeof(int));
	*p1 = 10;
	cout<< "*p1 = " << *p1 << endl;
	free(p1);

	int *p2 = new int(1);
	cout << "*p2 = " << *p2 << endl;
	delete p2;

	int *p3 = (int*)malloc(10*sizeof(int));
	free(p3);

	int *p4 = new int[10](); //new表达式而言，申请/释放数组空间时需要加上[]
	for(int idx=0;idx!=10;idx++)
	{
		p4[idx]=idx;
		cout<<p4[idx]<<endl;
	}
	delete [] p4;

	return 0;
}
