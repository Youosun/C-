#include <iostream>
using namespace std;
//单例对象自动资源释放
//版本一；静态对象 + 嵌套类
//
class Singleton
{
private:
	class GC //垃圾自动回收类
	{
	public:
		GC()
		{
			cout << "GC()" << endl;
		}
		~GC()
		{
			cout << "~GC()" << endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
public:
	static Singleton * getInstance()//多线程环境下并不是线程安全的
	{
		if(NULL == _pInstance)
		{
			_pInstance = new Singleton;
		}
		return _pInstance;
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
	static GC gc;  //注意垃圾回收类对象必须为静态对象
};

//懒汉式  初始为NULL  懒加载   保证线程安全时加锁
//Singleton * Singleton::_pInstance = NULL;
Singleton * Singleton::_pInstance = Singleton::getInstance();//饿汉式  可以保证是线程安全的  但有可能初始化之后全程未使用  浪费资源
Singleton::GC Singleton::gc;

int main(void)
{
	Singleton::getInstance();

	return 0;
}
