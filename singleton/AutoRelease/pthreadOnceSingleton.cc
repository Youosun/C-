#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//单例对象空间自动释放：
//版本三：atexit + pthread_once(多线程环境中，pthread_once注册的函数只会执行一次)
//此时无论如何getInstance()都是线程安全的函数  由pthread_once()内部函数实现去保证

class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton;
		atexit(destroy);
	}
	
	static void destroy()
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
	static pthread_once_t _once;;
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton::getInstance();

	return 0;
}
