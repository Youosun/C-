#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class String
{
	//设计模式之代理模式
	class CharProxy
	{
	public:
		CharProxy(String & str, size_t idx)
		: _str(str)
		, _idx(idx)
		{}

		CharProxy & operator=(const char & ch);

		friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	private:
		String & _str;
		size_t _idx;
	};
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);

	~String();
	
	//char & operator[](size_t idx);//下标访问运算符函数   返回某个字符的引用时  不能断定读写操作 
	CharProxy operator[](size_t idx);

	const char * c_str() const
	{
		return _pstr;
	}

	size_t size() const
	{
		return strlen(_pstr);
	}

	size_t refcount()const
	{
		return _pstr[size() + 1];
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);
	friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);

private:
	void initRefcount()
	{
		_pstr[size() + 1] = 1;
	}

	void increaseRefcount()
	{
		++_pstr[size() + 1];
	}

	void decreaseRefcount()
	{
		--_pstr[size() + 1];
	}
private:
	char * _pstr;
};

String::String()
: _pstr(new char[2]())
{
	initRefcount();
}

String::~String()
{
	decreaseRefcount();
	if(refcount() == 0)
	{
		delete [] _pstr;
	}
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 2]())
{
	strcpy(_pstr, pstr);
	initRefcount();//先拷贝  再进行引用计数的初始化
}

String::String(const String & rhs)
: _pstr(rhs._pstr) //这里使用浅拷贝
{
	increaseRefcount();	
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)  //先判断是否是自复制
	{
		decreaseRefcount();//建议左值的引用计数
		if(refcount() == 0)//只有当refcount变为0时，才去回收左值
		{
			delete [] _pstr;
		}
		_pstr = rhs._pstr;//浅拷贝  共用右值
		increaseRefcount();//增加右值的引用计数
	}
	return *this;
}

String::CharProxy String::operator[](size_t idx)
{//对于操作符[]来说  返回带有String类型的引用 + idx -->CharProxy
	return CharProxy(*this, idx);
}
//通过CharProxy的=运算符的重载  具体处理原来String类型的写操作
//CharProxy << 运算符的重载  处理原来String类型的读操作
String::CharProxy & String::CharProxy::operator=(const char & ch)
{
	if(_idx < _str.size())
	{
		if(_str.refcount() > 1)
		{
			_str.decreaseRefcount();
			char * ptmp = new char[strlen(_str._pstr) + 2]();
			strcpy(ptmp, _str._pstr);

			_str._pstr = ptmp;  //重新另起炉灶 
			_str.initRefcount();
		}
		_str._pstr[_idx] = ch;//更改拷贝过的string
	}
	return *this;

}
#if 0
//问题：下边访问运算符本身并不能区分用户的读写操作   故需要代理模式
char & String::operator[](size_t idx)  //针对写操作
{
	if(idx < size())
	{
		if(refcount() > 1)
		{
			decreaseRefcount();
			char * ptmp = new char[strlen(_pstr) + 2]();
			strcpy(ptmp, _pstr);

			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}
	else
	{
		static char nullchar = '\0';
		cout << "数组越界" << endl;
		return nullchar;
	}
}
#endif

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

//对于读操作
std::ostream & operator<<(std::ostream & os, const String::CharProxy & rhs)
{
	os << rhs._str._pstr[rhs._idx];
	return os;
}

int main(void)
{
	String str;
	cout << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	printf("&str = %p\n", str.c_str());

	String str2("hello,world");
	String str3(str2);
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	cout << endl;

	str = str2;//str引用计数为1
	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	cout << "---------" << endl;

	String str4 = "wangdao";
	String str5(str4);
	cout << "str4 = " << str4 << endl;
	cout << "str5 = " << str5 << endl;
	printf("&str4 = %p\n", str4.c_str());
	printf("&str5 = %p\n", str5.c_str());
	cout << "str4's refcount = " << str4.refcount() << endl;
	cout << "str5's refcount = " << str5.refcount() << endl;
	cout << endl;

	str4 = str2;//str4引用计数为2
	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;
	cout << "str5's refcount = " << str5.refcount() << endl;
	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());
	printf("&str5 = %p\n", str5.c_str());

	cout << endl << "-------------写操作" << endl;
	str[0] = 'H';

	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;

	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());

	cout << endl << "-------------读操作" << endl;
	cout << str2[0] << endl;
	
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;

	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());

	return 0;
}
