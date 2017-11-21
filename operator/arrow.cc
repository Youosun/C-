#include <iostream>
using namespace std;

class Data
{
public:
	Data()
	: _size(5)
	{}

	int length()
	{
		return _size;
	}
private:
	int _size;
	friend std::ostream & operator<<(std::ostream & os, const Data & rhs);
};

std::ostream & operator<<(std::ostream & os, const Data & rhs)
{
	os << rhs._size;
	return os;
}

class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{}

	Data * operator->()
	{
		return _pData;
	}

	Data & operator*()
	{
		return *_pData;
	}

	~DataPtr()
	{
		delete _pData;
	}
private:
	Data * _pData;
};

class ThirdLayer
{
public:
	ThirdLayer()
	: _p(new DataPtr)
	{}

	~ThirdLayer()
	{
		delete _p;
	}

	DataPtr & operator->()
	{
		return *_p;
	}

//	DataPtr * operator->()  当返回指针时 t1->length()无法调用
//	{
//		return _p;
//	}
private:
	DataPtr * _p;
};

int main(void)
{
	DataPtr dp;
	cout << dp->length() << endl;
	cout << dp.operator->()->length() << endl;

	cout << "data = " << *dp << endl;

	ThirdLayer t1;
	cout << t1->length() << endl;
	cout << t1.operator->().operator->()->length() << endl;

	return 0;
}
