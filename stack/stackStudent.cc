#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//只生成栈对象
class Student
{
public:
	Student(int id,const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name,name);
		cout << "Student(id,name)" << endl;
	}

	void print()const
	{
		cout << "ID = " << _id << endl
			 << "name = " << _name << endl;
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student " << endl;
	}

private:
	void * operator new(size_t size); 
	void operator delete(void * ret);
	//因为生成堆对象时需要调用operator new和operator delete函数进行申请和释放空间
	//所以将两个函数放入private  禁止类外调用----禁止类外生成堆对象
	//同时不关心如何实现
private:
	int _id;
	char * _name;
};
