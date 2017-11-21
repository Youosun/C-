#include <iostream>
#include <string>
using std::cout;
using std::endl;

//引用传递的好处：
//  在参数传递时，可以减少复制的开销，提高程序的执行效率
//  使用起来更加直观

//引用的底层实现还是指针

//引用与指针的差别：
//1、指针是一个独立的实体，而引用是一个别名
//2、指针是不需要进行初始化，而引用必须要进行初始化
//3、指针可以改变指向，引用一经绑定无法改变
//4、指针可以设置为NULL，引用则不行

int arr[5]={0,1,2,3,4};

//引用作为函数的返回值，返回时不会进行复制  其他类型的返回值则会进行复制
//那么返回的变量的生命周期一定要大于函数
int & func(int idx)
{
	return arr[idx];
}

int & func3() //不要返回局部变量的引用 
{
	int a = 3;//局部变量   但函数执行结束时，a的生命周期已经结束，它已经被销毁
	return a;
}

//不要轻易返回堆空间变量的引用
//除非你已经做好了内存回收的策略
int & func4()
{
	int *p = new int(1);
	return *p;
}

void test4()
{
	int & ref = func4();   //使用引用ref接收func4()返回的引用
	cout<< "ref = " << ref <<endl;

	delete (&ref);   //释放func4()申请的堆空间 
}

void test5()
{
	int a=3,b=4;
	int c = a + func4() + b;//func4()每执行一次就会发生内存泄漏
	cout << "c = " << c << endl;
}

void swap(int & refa,int & refb)
{
	int tmp = refa;
	refa = refb;
	refb = tmp;
}

int main(void)
{
	int a=3;
	int b=4;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;

	swap(a,b);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;

	return 0;
}
