#include <string.h>
#include <stdio.h>

#include <iostream>
using namespace std;

template <typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()
		{
			cout << "~AutoRelease()" << endl;
			if(_pInstance)
				delete _pInstance;
		}
	};
public:
	static T * getInstance();
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
	static T * _pInstance;
	static AutoRelease _auto;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL; //饿汉式

#if 0
template <typename T>
T * Singleton<T>::_pInstance = getInstance();//饱汉式
#endif

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;  //注意此处的typename 向编译器声明AutoRelease是一个类型

template <typename T>
T * Singleton<T>::getInstance()
{
	if(NULL == _pInstance)
	{
		_auto; //点明一下 _auto 变量的存在 否则 编译器不会构造AutoRelease类型的变量_auto  
				//该语句可以是AutoRelease类型得以构造  进而析构时回收空间
		_pInstance = new T();
	}
	return _pInstance;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point()" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	void init(int ix, int iy)  //当Point类型被放入单例模板当中时  无法通过有参数的构造函数去构造特定的Point对象  只能是默认的对象
	{							//所以这里需要通过接口去设置对象的属性
		_ix = ix;
		_iy = iy;
	}
private:
	int _ix;
	int _iy;

};
int main(void)
{
	Point * p1 = Singleton<Point>::getInstance(); //先创建对象 
	Point * p2 = Singleton<Point>::getInstance();

	p1->init(1, 2);//再去进行初始化，  二段式构造
	p1->print();

	p2->print();

	printf("p1 = %p\n", p1);
	printf("p2 = %p\n", p2);
	return 0;
}
