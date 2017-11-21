#include <math.h>
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

//能够满足面向对象设计原则之开闭原则
//
//1. 通过继承和虚函数方式实现实现多态
class Figure
{
public:
	virtual void display()const=0;
	virtual float area()=0;
};

class Rectangle
: public Figure
{
public:
	Rectangle(float flength, float fwidth)
	: _flength(flength)
	, _fwidth(fwidth)
	{}

	virtual void display() const
	{
		cout << "Rectangle: " << endl;
	}

	virtual float area()
	{
		return _flength * _fwidth;
	}
private:
	float _flength;
	float _fwidth;

};

class Circle
: public Figure
{
public:
	Circle(float  fradius)
	: _fradius(fradius)
	{}

	virtual void display()const
	{
		cout << "Circle: " << endl;
	}

	virtual float area()
	{
		return PI * _fradius * _fradius;	
	}
private:
	float _fradius;
	static float PI;
};

float Circle::PI = 3.14159;


void display(Figure * fig)
{
	fig->display();
	cout << fig->area() << endl;
}

//静态工厂方法
// 优点: 创建图形对象时是比较统一的
// 缺点: 1. 不满足单一职责原则: 可以创建多种图形
//		 2. 不满足开放闭合原则: 如果要创建新的图形,
//								就必须修改FigureFactory类
//								增添新的图形创建函数

class FigureFactory
{
public:
	static Figure * createCircle()
	{
		//load configuration file
		//reading statistics
		int radius = 3;
		return new Circle(radius);
	}

	static Figure * createRectangle()
	{
		//load config file
		//reading statistics
		float length = 3;
		float width = 4;
		return new Rectangle(length, width);
	}


	//创建新的图形时, 需要修改FigureFactory类  添加新的创建函数
	static Figure * createDiamond()
	{
		//...
	}
};

int main(void)
{
	std::unique_ptr<Figure> circle(FigureFactory::createCircle());
	std::unique_ptr<Figure> rectangle(FigureFactory::createRectangle());

	display(circle.get());
	display(rectangle.get());

	return 0;
}
