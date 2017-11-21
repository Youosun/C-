#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

class Test
{
public:
	static Test * getInstance()
	{
		if(t == NULL)
		{
			t = new Test();
		}
		return t;
	}

	~Test()
	{
		cout << "~Test()" << endl;
	}

private:
	Test()
	{
		cout << "Test()" << endl;
	}
	static Test * t;
	//static A a;
	A a;
};

Test * Test::t = NULL;
//A Test::a;


int main(void)
{
	Test * t1 = Test::getInstance();//单例模式中单个实例存在于堆空间中  程序结束时不能主动调用析构函数释放空间  需要手动释放
	Test * t2 = Test::getInstance();//而自动化的垃圾回收机制  借助于单例类中另一个静态对象在析构A时  手动释放Test申请的空间
									//如果另一个对象不是静态类型  因为析构过程为先析构Test  再析构A
									//而此时Test的析构函数并不会被调用  所以A的析构函数也就不会被调用  导致通过A的析构  释放Test的空间做法失败
	return 0;
}
