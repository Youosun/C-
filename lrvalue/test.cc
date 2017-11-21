#include <iostream>
#include <vector>
#include <string>
using namespace std;

void test0()
{
	int && ref = 10;//c++11新特性  右值引用  只能绑定到右值
	cout << ref << endl;

	int a = 10;
	//int && ref = a; //error 右值引用不能绑定左值
}

int mian(void)
{
	int a = 1;
	int b = 2;
	int * p = &a;
	vector<int> vec;
	vec.push_back(1);

	&a;
	&b;
	&(a + b); //error 右值
	&(a++);		//error 后置++ 右值
	&(++a);  //左值

	&p;
	&*p;//&a 

	&(vec[0]);
	&100; //error字面值  右值

	&string("helloworld");  //error  string匿名对象  右值
	int & ref = 1;//非const的左值引用 不能绑定到右值
	const int & ret = 1;//const左值引用  能够绑定到右值
	const int & ref = a;//const左值引用  同时也能绑定到左值
		//因此 当const左值引用作为函数参数时
		//无法确定其传递过来的是左值还是右值


	string s1 = "hello";
	string s2= "world";

	&(s1 + s2);  //error 计算的中间结果  右值

	return 0;
}
