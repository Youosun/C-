#include <stdlib.h>
#include <iostream>
using namespace std;

//单例对象空间的自动释放
//版本二：atexit(注册退出处理函数) + 饿汉式
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
			atexit(destroy);
		}
		return _pInstance;
	}

	static void destroy(void)
	{
		if(_pInstance)
			delete _pInstance;
	}
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}
	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = getInstance();//饿汉式，保证线程安全
												//此处可以不用加 Singleton::getInstance
												//初始化静态的成员变量相当于在类内进行初始化
												//类中的数据成员与成员函数可以直接访问
int main(void)
{
	Singleton::getInstance();

	return 0;
}
