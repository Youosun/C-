#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

class String
{
public:
	String()
	: _pstr(new char[1])
	{}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char*) " << endl;
		strcpy(_pstr, pstr);
	}

	//复制构造函数   只有复制语义
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String &)" << endl;
		strcpy(_pstr, rhs._pstr);
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	//移动赋值运算符函数   //具有移动语义的函数会优先执行
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String && rhs)" << endl;
		if(this != &rhs)
		{
			delete [] _pstr;
			_pstr = rhs._pstr;  //只进行浅拷贝
			rhs._pstr = NULL;	//将右值设为NULL

		}
		return *this;
	}

	//移动构造函数
	String(String && rhs)//传递过来的实参是右值,但在函数体内获得了名字转换为左值
	: _pstr(rhs._pstr)  //浅拷贝
	{
		rhs._pstr = NULL;
		cout << "String(String && rhs)" << endl;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
private:
	char * _pstr;
};

 std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

void test0()
{
	vector<String> vec;
	vec.push_back("hello,world");  //此处先调用了char*的构造函数
								//接着调用了移动构造函数---匿名对象  移动到vector
}

void test1()
{
	String s1("hello");
	String s2("wangdao");
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	s1 = "world";   //此处调用了移动构造函数  s1的hello先被析构  world取而代之
	cout << "s1 = " << s1 << endl;

	cout << endl;
//	s2 = s1; //调用赋值运算符函数
	s2 = std::move(s1); //move函数的作用就是强制把一个左值转换为右值
						//注意使用移动语义时，该语句之后  移动源被清除  对象不再被使用
	cout << "s1 = " << s1 << endl; //此处s1为空指针  cout直接崩溃
	cout << "s2 = " << s2 << endl;
	
	cout << "--------" << endl; //此语句不会被打印
}

int main(void)
{
//	test0();
	test1();


	return 0;
}
