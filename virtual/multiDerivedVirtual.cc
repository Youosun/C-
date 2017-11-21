#include <stdio.h>
#include <iostream>
using namespace std;

class A
{
public:
	virtual void a() {	cout << "A::a()" << endl;  }
	virtual void b() {	cout << "A::b()" << endl;  }
	virtual void c() {	cout << "A::c()" << endl;  }
private:
	double _dx;
};

class B
{
public:
	virtual void a() {	cout << "B::a()" << endl;	}
	virtual void b() {	cout << "B::b()" << endl;	}
	void c(){	cout << "B::c()" << endl;	}
	void d(){	cout << "B::d()" << endl;	}
private:
	double _dy;
};

class C
: public A
, public B
{
public:
	virtual void a(){	cout << "C::a()" << endl;	}
	void c() {	cout << "C::c()" << endl;	}
	void d() {	cout << "C::d()" << endl;	}
private:
	double _dx;
};

int main(void)
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
	cout << "sizeof(C) = " << sizeof(C) << endl;

	A a;
	B b;
	C c;

	c.a();  //通过对象调用  静态联编
//	c.b();//error 二义性
	b.a();
	c.d();
	cout << endl;

	A * pA = &c;  //虚函数是指在基类中是虚函数  派生类中的虚函数特性只在下一继承层级中体现
	pA->a();//虚函数   C::a()   
	pA->b();//C中没有b() 调用A中虚函数b()  A::b()
	pA->c();//虚函数  C::c() ****  
			//此例中c()在基类中为虚函数  在派生类中被重写(不管重写函数是不是virtual)
			//所以调用派生类中的c()
	printf("pA = %p\n", pA);
	cout << endl;

	B *pB = &c;
	printf("pB = %p\n", pB);
	pB->a();//C::a() a()是虚函数  被重写
	pB->b();//B::b() b()是虚函数  但未被重写
	pB->c();//B::c() c()与d()在基类B中不是虚函数 在派生类C中被隐藏
	pB->d();//B::d()
	cout << endl;

	C * pC = &c;
	printf("pC = %p\n", pC);
	pC->a();
	//pC->b();//error 二义性
	pC->c();
	pC->d();

	return 0;
}
