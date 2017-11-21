#include <string.h>
#include <iostream>
using namespace std;

class Base
{
public:
	Base(const char * pbase)
	: _pbase(new char[strlen(pbase) + 1]())
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pbase, pbase);
	}

//	virtual  //当基类的析构函数不是虚函数时, 
	~Base()
	{
		cout << "~Base()" << endl;
		delete [] _pbase;
	}

	virtual
	void display()const
	{
		cout << _pbase;
	}
private:
	char * _pbase;
};

class Child
: public Base
{
public:
	Child(const char * pbase, const char * pchild)
	: Base(pbase)
	, _pchild(new char[strlen(pchild) + 1]())
	{
		cout << "Child(const char8,const char *)" << endl;
		strcpy(_pchild, pchild);
	}

	~Child()
	{
		cout << "~Child()" << endl;
		delete [] _pchild;
	}

	virtual
	void display()const
	{
		Base::display();
		cout << _pchild << endl;
	}
private:
	char * _pchild;
};

int main(void)
{
	Base * pbase = new Child("hello,","world");
//	Child child("nihao","China");  
	//当基类的析构函数不是虚函数时, 只对基类类型的指向派生类对象的指针(pbase)的delete有关
	//对于正常对象child无影响
									
	Child * pchild = new Child("hello,","world");
	pchild->display();

//	delete pbase;  //我们需要调用的是派生类的析构函数
				//而当基类的析构函数不是虚函数时,
				//则只调用了基类的析构函数 没有调用派生类的析构函数
				//导致对象不能正确析构
				//基类类型的指针对象不能正常析构

	delete pchild;  //派生类类型的指针对象(pchild)能够正常析构

	return 0;
}
