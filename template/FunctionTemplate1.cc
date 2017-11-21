#include <iostream>
using namespace std;

//模板参数推导
//函数模板  -->  模板函数
//			实例化
//模板  -->  代码生成器

template <typename T>
T add(T x, T y);//函数模板的声明

//函数模板与函数模板之间也可以进行重载
#if 0
template <typename T>
T add(T x, T y, T z)
{
	return x + y + z;
}
#endif

//模板函数：根据实参传递时的类型自动推导
#if 0
int add(int x, int y)
{
	return x + y;
}
#endif

//函数模板与普通函数是可以进行重载的
//重载之后，优先执行普通函数
double add(double x, double y)
{
	cout << "double add(double double)" << endl;
	return x + y;
}

int main(void)
{
	int ia = 1, ib = 2;
	double da = 3.3, db = 4.2;
	char ca = 'A', cb = 1;

	cout << "int add = " << add(ia, ib) << endl;  //隐式函数模板的实例化
	cout << "double add = " << add<double>(da, db) << endl;//显式实例化
	cout << "char add = " << add(ca, cb) << endl;

	return 0;
}

//函数模板的实现  函数模板声明与实现的分离
template <typename T>
T add(T x, T y)
{
	return x + y;
}
