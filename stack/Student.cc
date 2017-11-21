#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name)+1]())
	{
		strcpy(_name,name);
		cout << "Student(int,const char *)" << endl;
	}

	Student(const Student & rhs)
	: _id(rhs._id)
	, _name(new char[strlen(rhs._name)+1]())
	{
		strcpy(_name,rhs._name);
		cout << "Student(const Student &)" << endl;
	}

	Student & operator=(const Student & rhs)
	{
		if(this != &rhs)
		{
			delete [] _name;
			_name = new char[strlen(rhs._name) + 1]();
			strcpy(_name,rhs._name);
			cout << "operator=(const Student &)" << endl;
		}
		return *this;
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student" << endl;
	}

	void print() const
	{
		cout << "name = " << _name << endl;
		cout << "ID = " << _id << endl;
	}

	void * operator new(size_t size)
	{
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);
		return ret;
	}

	void operator delete(void * ret)
	{
		cout << "void operator delete(void *)" << endl;
		free(ret);
	}

private:
	int _id;
	char * _name;
};

int main(void)
{											//重点理解
	Student * ps1 = new Student(100,"Mike");//这个说明了new操作符
											//1.通过operator new函数先分配原始的、未标注类型的空间
	ps1->print();							//2.在通过对象的构造函数构造对象
											//3.最后返回指向构造类型对象的指针
											
	delete ps1;								//delete操作符
											//1.先通过析构函数销毁对象
											//2.再调用operator delete函数释放空间

	return 0;
}
