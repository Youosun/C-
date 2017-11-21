#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int a = 0; //全局区
const int t = 20;//放在了文字常量区
char * p1;

int main(void)
{
	int b;	//main函数栈区
	const int d = 40;//放在了栈区，与其生命周期有关
	char s[] = "123456"; //main函数栈区
	char *p2;//p2本身在栈区
	const char * p3 = "123456";//p3本身在栈区(&p3)  指向了文字常量区的内容(p3)
	static int c = 0;  //静态全局区
	p1 = new char[10];//p1指向了堆区p1   本身在全局区&p1
	p2 = new char [5];// p2指向了堆区分配的空间
	strcpy(p1, "123456");

	printf("123456 = %p\n","123456");//“123456” 总是在文字常量区

	printf("&a = %p\n",&a);
	printf("&c = %p\n",&c);
	printf("&p1 = %p\n",&p1);
	printf(" p1 = %p\n",p1);
	printf("&p2 = %p\n",&p2);
	printf(" p2 = %p\n",p2);
	printf("&p3 = %p\n",&p3);
	printf(" p3 = %p\n",p3);
	printf("&b = %p\n",&b);
	printf("s = %p\n",s);

	printf("&d = %p\n",&d);
	printf("&t = %p\n",&t);

	return 0;
}

