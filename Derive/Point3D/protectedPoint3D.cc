#include <iostream>
using namespace std;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print()const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" <<endl;
	}

	int getX() const
	{
		return _ix;
	}
private:
	int _ix;
protected://对其派生类进行开放
	int _iy;
};

class Point3D
: protected Point  
//采用protected进行继承时,
//	除了基类的private成员不能在派生类中访问之外
//	其他的成员都可以在派生类内部进行访问
{
public:
	Point3D(int ix, int iy, int iz)
	: Point(ix, iy)
	, _iz(iz)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void display()const
	{
		//cout << "(" << _x  //不论以何种方式进行继承,
							//基类中的private成员在派生类中均不能访问
		cout << "(" << getX()
			 << "," << _iy  //基类的public/protect成员可以在派生类中访问
		     << "," << _iz	//但_iy在派生类中访问权限变为private成员
		     << ")" << endl;
	}
private:
	int _iz;
};

class Point4D
: public Point3D
{
public:
	void show()const
	{
		cout << getX() //protected继承时,除了基类的私有成员在整个继承体系中不能直接在派生类内部访问之外 
			//	其他非私有成员均可在继承体系派生类内部进行访问
			 << _iy
			 << _iw;
	}
private:
	int _iw;
};

int main(void)
{
	Point3D p1(1, 2, 3);
	p1.display();
	//p1.print();  //error  基类的print()在Point3D派生类中变成protected的
				//不能直接通过对象在类外进行访问

	Point p2(6, 6);
	p2.print();
	p2._iy = 10; //protected成员不能直接通过对象进行访问
	p2.print();
	cout << "x = " << p2.getX() << endl;
	return 0;
}
