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

	std::weak_ptr<Child> _childPtr;
	//weak_ptr就是用来解决shared_ptr的循环引用问题
//	std::shared_ptr<Child> _childPtr;

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

	std::shared_ptr<Parent> _parentPtr;
};

int main(void)
{
	shared_ptr<Parent> parent(new Parent());
	cout << "parent's use_count = " << parent.use_count() << endl;

	shared_ptr<Child> child(new Child());
	cout << "child's use_count = " << child.use_count() << endl;

	//_childPtr是一个weak_ptr
	parent->_childPtr = child;//进行复制,引用计数不会加1
	cout << "child's use_count = " << child.use_count() << endl;

	child->_parentPtr = parent;//进行复制,引用计数+1
	cout << "parent's use_count = " << parent.use_count() << endl;
	//循环引用中,其中一个类中定义为weak_ptr在类外进行复制时 引用计数不变
	//Parent类析构时会将类内的weak_ptr析构 进而将Child类内的shared_ptr引用计数 - 1
	//最后当child对象析构时,彻底析构Child类内的shared_ptr

	return 0;
}
