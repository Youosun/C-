#include <stdio.h>

#include <iostream>
using namespace std;

int main(void)
{
	int a = 1;

	printf("sizeof(a) = %lu\n",sizeof a);  //sizeof是操作符  变量或对象  不需要加()

	printf("sizeof(a) = %lu\n",sizeof(int));//类型 需要添加()

	return 0;
}
