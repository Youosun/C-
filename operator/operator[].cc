#include <string.h>
#include <iostream>
using namespace std;

class CharArr
{
public:
	CharArr(int size)
	: _size(size)
	, _arr(new char[_size]())
	{
	}

	~CharArr()
	{
		delete [] _arr;
	}

	int size() const
	{
		return _size;
	}

	char & operator[](int idx);
private:
	int _size;
	char * _arr;
};

char & CharArr::operator[](int idx)
{
	static char nullchar = '\0'; //不返回非静态的局部变量
	if(idx >= 0 && idx < _size)
	{
		return _arr[idx];
	}
	else{
		cout << "下标越界" << endl;
		return nullchar;
	}
}

int main(void)
{
	const char * str = "helloworld";
	int len = strlen(str);

	CharArr ca(len);

	for(int idx = 0; idx < len; ++idx)
	{
		ca[idx] = str[idx];
	}
	ca[0] = 'H';

	for(int idx = 0; idx < len; ++idx)
	{
		cout << ca[idx] << endl;
	}
	return 0;
}
