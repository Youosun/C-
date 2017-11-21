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

//设计模式之工厂模式
//优点:
//	1. 满足单一职责原则
//	2. 满足开闭原则
//
//适用场景:
//  1. 复杂对象的创建
//  2. 有多个同类型的对象, 提供统一的接口
//
//注意: 如果创建的是一个简单对象, 完全没有必要使用工厂模式

//生产工厂作为一个虚基类提供create()的统一接口
class FigureFactory
{
public:
	virtual Figure * create()=0;
};

//具体的图形工厂继承自FigureFactory, 提供具体图形的create函数
//
//存在抽象层与实现层
//  抽象层: Figure   FigureFactory
//	实现层: Circle/Rectangle   circleFactory/RectangleFactory

class circleFactory
: public FigureFactory
{
public:
	Figure * create()
	{
		//load config file
		int radius = 5;
		return new Circle(radius);
	}
};

class RectangleFactory
: public FigureFactory
{
public:
	Figure * create()
	{
		//load config file
		float length = 3;
		float width = 4;
		return new Rectangle(length, width);
	}
};

int main(void)
{
	std::unique_ptr<FigureFactory> cf(new circleFactory());
	std::unique_ptr<FigureFactory> rf(new RectangleFactory());
	//先创建工厂

	unique_ptr<Figure> circle(cf->create());
	unique_ptr<Figure> rectangle(rf->create());
	//再由工厂创建图形对象

	display(circle.get());
	display(rectangle.get());

	return 0;
}
