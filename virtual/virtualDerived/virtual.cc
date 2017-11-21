//
///  @filename   
///  @author     whao Luo
///  @email      haohb13@gmail.com
///  @date       
///

#if 0
#include <iostream>
using std::cout;
using std::endl;


class A
{
public:
	virtual void a1(){}
	virtual void a2(){}
private:
	char ar[3];
};

class B :virtual public A
{
public:
	virtual void b1(){}
};


int test(void)
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	getchar();
	return 0;
}

void func(int * p)
{
	*p = 10;
}

int main(void)
{
	const int arr[5] = {1, 2, 3, 4, 5};
	func(&arr[3]);

	printf("%d\n", arr[3]);
	return 0;
}


#endif

#if 0
//测试虚表的存在

#include <iostream>
using namespace std;
class A
{
	int i = 10;
	int ia = 100;
	void func(){}
	virtual void run(){	cout << "A::run()" << endl;	}
	virtual void run1(){	cout << "A::run1()" << endl;	}
	virtual void run2(){	cout << "A::run2()" << endl;	}
};
class B : public A
{
	virtual void run(){	cout << "B::run()" << endl;	}
	virtual void run1(){	cout << "B::run1()" << endl;	}
};
class C :public A
{
	virtual void run(){	cout << "C::run()" << endl;	}
	virtual void run1(){	cout << "C::run1()" << endl;	}
	virtual void run3(){	cout << "C::run3()" << endl;	}
};
class D :/*virtual*/ public A
{
	virtual void run(){	cout << "D::run()" << endl;	}
	virtual void run1(){	cout << "D::run1()" << endl;	}
	virtual void run2(){	cout << "D::run2()" << endl;	}
	virtual void run3(){	cout << "D::run3()" << endl;	}
};

int test()
{
	cout << sizeof(A) << endl
		<< sizeof(B) << endl
		<< sizeof(C) << endl
		<< sizeof(D) << endl;

	//A * pA = new D;
	D d;
	//d.run();

	typedef void(*Function)(void);

	int ** pVtable = (int **)&d;

	//pVtable[0][0]

	for (int idx = 0; pVtable[0][idx] != NULL; ++idx)
	{
		Function f = (Function)pVtable[0][idx];
		f();
	}

	cout << (int)pVtable[1] << endl;
	cout << (int)pVtable[2] << endl;

	getchar();
	return 0;
}

int main(void)
{
	test();
	return 0;
}

#endif



#if 1
// 测试一：单个虚继承，不带虚函数
//	虚继承与继承的区别
//	１.　多了一个虚基指针
//	２.　虚基类位于派生类存储空间的最末尾

// 测试二：单个虚继承，带虚函数
//   1.如果派生类没有自己的虚函数，此时派生类对象不会产生
//　   虚函数指针
//   2.如果派生类拥有自己的虚函数，此时派生类对象就会产生自己本身的虚函数指针，
//     并且该虚函数指针位于派生类对象存储空间的开始位置
//



#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A() : _ia(10){}

	virtual
	void f()
	{	cout << "A::f()" << endl;	}
private:
	double _ia;
};

class B 
:  virtual public A
{
public:
	B() : _ib(20){}

	void fb()
	{	cout << "A::fb()" << endl;	}

#if 0
//	virtual 
	void f()
	{	cout << "B::f()" << endl;	}


//	virtual 
	void fb2()	
	{	cout << "B::fb2()" << endl;	}
#endif

private:
	double _ib;
};

int main(void)
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	B b;
	return 0;
}

#endif
