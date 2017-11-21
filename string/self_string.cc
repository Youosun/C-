#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
	String()
	: _pstr(new char[1]())
	{
		cout << "string()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr,pstr);
		cout << "String(const char *)" << endl;
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout << "String(const String &)" << endl;
	}

	String & operator=(const String & rhs)
	{
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr)+1]();
			strcpy(_pstr,rhs._pstr);
		}
		return *this;
		cout << "operator=(const String &)" << endl;
	}

	String & operator=(const char * pstr)
	{
		delete [] _pstr;
		_pstr = new char[strlen(pstr)+1]();
		strcpy(_pstr,pstr);
		cout << "operator=(const char *)" << endl;
		return *this;
	}

	void print()
	{
		cout << _pstr << endl;//cout不能输出空指针  如果输出空指针  程序直接崩溃
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
private:
	char * _pstr;
};

int main(void)
{
	String s1 = "hello world"; //这里存在隐式类型转换
	s1.print();

	String s2 = s1;
	s2.print();

	String s3(s1);
	s3.print();

	String s4("C++");
	s4.print();

	s4 = s1;
	s4.print();

	String s5;
	s5.print();
	s5 = s1;
	s5.print();
	return 0;
}
