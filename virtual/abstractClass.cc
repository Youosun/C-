#include <iostream>
using namespace std;

class Base
{
//定义了protected型构造函数的类也是抽象类
//  只能继承  不能创建对象
public:
//	virtual	  //多态的实现依赖
	void display()const
	{
		cout << "Base::_ix = " << _ix << endl;
	}
protected:
	Base(int ix) : _ix(ix) {}
private:
	int _ix;
};

class Child : public Base
{
public:
	void display() const
	{
		Base::display();
		cout << "Child::_iy = " << _iy << endl;
	}

	Child(int ix, int iy)
	: Base(ix)
	, _iy(iy)
	{}
private:
	int _iy;
};

int main(void)
{
	//Base base(10);//error
	Base * pbase = new Child(1, 2);  //虽然也能创建抽象类
	pbase->display();	//多态机制的实现仍然需要virtual

	return 0;
}
