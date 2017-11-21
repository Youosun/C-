#include <stdlib.h>
#include <iostream>
using namespace std;


void display(void)
{
	cout << "display()" << endl;
}

void display1()
{
	cout << "display1()" << endl;
}

void display2()
{
	cout << "display2()" << endl;
}

int main(void)
{
	cout << "enter main()" << endl;
	atexit(display1); //注册函数执行的顺序 按照函数注册时的函数栈依次弹栈执行
	atexit(display);
	atexit(display2);
	cout << "exit main()" << endl;

	return 0;
}
