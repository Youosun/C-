#include <iostream>
#include <memory>
using namespace std;

class X
{
	public:
		X()
		{
			cout << "X()" << endl;
		}

		~X() 
		{
			cout << "~X()" << endl;
		}

		void func()
		{
			cout << "X::func()" << endl;
		}
};

int main(void)
{
	//	std::weak_ptr<X> sp(new X()); 
	weak_ptr<X> wp;
	{
		shared_ptr<X> sp(new X());
		cout << "sp's use_count = " << sp.use_count() << endl;

		wp = sp;
		cout << "sp's use_count = " << sp.use_count() << endl;

		shared_ptr<X> sp2 = wp.lock();
		if(sp2)
		{
			cout << "提升成功" << endl;
			sp2->func();
		}
		else
		{
			cout << "提升失败,该对象已被销毁" << endl;
		}
	}
	shared_ptr<X> sp2 = wp.lock();
	if(sp2)
	{
		cout << "提升成功" << endl;
		sp2->func();
	}
	else
	{
		cout << "提升失败,该对象已被销毁" << endl;
	}

	return 0;
}
