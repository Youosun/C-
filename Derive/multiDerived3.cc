#include <iostream>
using namespace std;

class A
{
public:
	A(int ix = 0)
	: _ix(ix)
	{}

	void setX(int ix)
	{
		_ix = ix;
	}

	void print()const
	{
		cout << "A::_ix = " << _ix << endl;
	}
private:
	int _ix;
};

class B: virtual public A
{};

class C : virtual public A
{};

class D
: public B
, public C
{};

int main(void)
{
	D d;
	d.setX(1); //菱形继承带来的存储二义性
				//解决: 采用虚继承
	d.print();

	return 0;
}
