#include <iostream>
#include <memory>
using namespace std;

class Child;

class Parent
{
public:
	Parent()
	{
		cout << "Parent()" << endl;
	}

	~Parent()
	{
		cout << "~Parent()" << endl;
	}
	shared_ptr<Child> _childPtr;
};

class Child
{
public:
	Child()
	{
		cout << "Child()" << endl;
	}

	~Child()
	{
		cout << "~Child()" << endl;
	}
	shared_ptr<Parent> _parentPtr;
};

int main(void)
{
	shared_ptr<Parent> parent(new Parent);

	shared_ptr<Child> child(new Child);

	parent->_childPtr = child; //进行复制,引用计数加1
	child->_parentPtr = parent;//复制,引用计数加1
	//循环引用问题:
	//堆空间的new Parent 和 new Child引用计数各为2
	//栈空间中的智能指针在释放时,只能将引用计数减一 
	//所以程序结束时 对象的析构函数并不能被调用

	return 0;
}
