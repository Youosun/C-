#include <stdio.h>
#include <iostream>
#include <memory>
using namespace std;

int main(void)
{
	int * p1 = new int(66);
	std::auto_ptr<int> api(p1);
	cout << "*api = " << *api << endl;
	cout << "*p1 = " << *p1 << endl;

	printf("api's ptr = %p\n", api.get());
	printf("p1 = %p\n", p1);

	std::auto_ptr<int> api2 = api;  //在语法层面是表达复制语义
									//但在实现上，右操作数将托管的对象指针交给了左操作数
									//发生了所有权的转移
									//这与复制语义相矛盾
									//所以auto_ptr指针存在缺陷

	//类似语义上是复制  实现上是移动语义
	cout << "*api2 = " << *api2 << endl;
	cout << "*api = " << *api << endl;  //此时api不能再正常使用

	return 0;
}
