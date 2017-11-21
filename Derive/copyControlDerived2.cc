#include <string.h>
#include <iostream>
using namespace std;

class Base
{
public:
	Base(const char * pdata1)
	: _pdata1(new char[strlen(pdata1) + 1]())
	{
		cout << "Base(const char *)" << endl;
		strcpy(_pdata1, pdata1);
	}

	Base(const Base & rhs)
	: _pdata1(new char[strlen(rhs._pdata1) + 1]())
	{
		cout << "Base(const Base &)" << endl;
		strcpy(_pdata1, rhs._pdata1);
	}

	Base & operator=(const Base & rhs)
	{
		cout << "Base & operator=(const Base & rhs)" << endl;
		if(this != &rhs)
		{
			delete [] _pdata1;
			_pdata1 = new char[strlen(rhs._pdata1) + 1]();
			strcpy(_pdata1, rhs._pdata1);
		}
		return *this;
	}

	~Base()
	{
		delete [] _pdata1;
		cout << "~Base()" << endl;
	}

	void display()const
	{
		cout << _pdata1 << endl;
	}
private:
	char * _pdata1;
};

class Derived
: public Base
{
public:
	Derived(const char * pdata1, const char * pdata2)
	: Base(pdata1)
	, _pdata2(new char[strlen(pdata2) + 1]())
	{
		cout << "Derived(const char *,const char *)" << endl;
		strcpy(_pdata2, pdata2);
	}

	Derived(const Derived & rhs)
	: Base(rhs)  //必须加上  显式利用派生类进行基类的初始化
	, _pdata2(new char[strlen(rhs._pdata2) + 1]())
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_pdata2, rhs._pdata2);
	}

	Derived & operator=(const Derived & rhs)
	{
		cout << "Derived & operator=(const Derived &)" << endl;

		if(this != &rhs)
		{
			Base::operator=(rhs);//利用派生类进行基类的初始化

			delete [] _pdata2;
			_pdata2 = new char[strlen(rhs._pdata2) + 1]();
			strcpy(_pdata2, rhs._pdata2);
		}
		return *this;
	}

	~Derived()
	{
		delete [] _pdata2;
	}

	void display() const 
	{
		Base::display();
		cout << "Derived:" << _pdata2 << endl;
	}
private:
	char * _pdata2;
};

int main(void)
{
	Derived d1("hello,","world");
	cout << "d1 = ";
	d1.display();
	cout << endl;

	Derived d2(d1);
	cout << "d2 = ";
	d2.display();
	cout << endl;

	Derived d3("zhengzhou,","daxue");
	cout << "d3 = ";
	d3.display();
	cout << "d1 = ";
	d1.display();

	cout << endl;
	d1 = d3;  //先调用基类的赋值运算符函数  再调用派生类的赋值运算符函数
	d1.display();

	return 0;
}
