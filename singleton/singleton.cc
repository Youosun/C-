#include <iostream>
#include <stdio.h>
using namespace std;

//要求：由该类只能生成唯一的对象
//1. 该对象不能是栈对象
//2. 该对象只能是堆对象

//主要作用：用来替换全局变量  全局唯一的变量，即用即得
//使用场景：配置文件的读取、词典类的实现、日志系统的输出对象

class Singleton
{
public:
	static Singleton * getInstance()   //static 限定符 指定要用类名调用该函数
	{
		if(_pInstance == NULL)         
			_pInstance = new Singleton();
		return _pInstance;            //只有第一次生成对象时才new出新对象
	}								  //后续的生成对象只返回第一次的对象的值
private:
	Singleton(){}
	static Singleton * _pInstance;    //static限定pInstance只保存第一次生成的对象的地址
};

Singleton * Singleton::_pInstance = NULL;

//Singleton s3;

int main(void)
{
	//Singleton s1; //禁止该语句运行，不能通过编译
	//Singleton s2; //需要在类之外调用默认构造函数
	//
	//Singleton s3 = new Singleton();

	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	Singleton * p3 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);

	return 0;
}
