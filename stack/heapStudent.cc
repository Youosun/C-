#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//只生成堆对象
class Student
{
public:
	Student(int id, const char * name)//因为类外堆对象的生成也需要调用构造函数  所以构造函数仍在public中
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name,name);
		cout << "Student(int,const char*) " << endl;
	}

	void destory()// 类外的堆对象通过特定的destory()函数  访问private的析构函数  销毁堆对象
	{
		delete this;  //重点理解
		//this->~Student();//error   只调用了析构函数销毁对象  并没有调用operator delete函数释放空间
	}

	void * operator new(size_t size)
	{
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);
		return ret;
	}

	void operator delete(void * ret)
	{
		cout << "void operator delete(void*)" << endl;
		free(ret);
	}

	void print()const
	{
		cout << "ID = " << _id << endl;
		cout << "name = " << _name << endl;
	}

private://因为栈对象的生成需要调用构造和析构函数  将其任何一个放入private都将禁止类外栈对象的生成
	~Student()
	{
		delete [] _name;
		cout << "~Student() " << endl;
	}

private:
	int _id;
	char * _name;
};
