#include <iostream>

using namespace std;

class Point 
{
public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int) " << endl;
	}

#if 0
	//系统提供的已经能够满足需求
	//对于类的数据成员来说  简单的浅拷贝就能够满足
	//		如果类中的数据成员中含有字符或string类型指针   则需要重载自己的赋值运算符  进行深拷贝
	Point & operator= (const Point & rhs)   //运算符重载函数返回的是左值的引用
	{
		_ix = rhs._ix;
		_iy = rhs._iy;
		
		return *this;
	}
#endif

	//this是一个隐含参数
	void print(/*const Point * this*/)
	{

		cout << "(" << this->_ix 
			 << "," << this->_iy
			 << ")" <<endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	Point pt1(1,2);
	pt1.print();
	Point pt2(3,4);

	pt2 = pt1; //如果没有提供赋值运算符 使用默认的重载的赋值运算符

	pt2.print();

	return 0;
}
