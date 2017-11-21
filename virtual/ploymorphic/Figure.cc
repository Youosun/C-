#include <math.h>
#include <iostream>
using namespace std;

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

	virtual void display()const
	{
		cout << "Rectangle : " << endl;
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
	Circle(float fradius)
	: _fradius(fradius)
	{}

	virtual void display()const
	{
		cout << "Circle : " << endl;
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


class Triangle
: public Figure
{
public:
	Triangle(float fa, float fb, float fc)
	: _fa(fa)
	, _fb(fb)
	, _fc(fc)
	{}

	virtual void display()const
	{	cout << "Triangle : " << endl;	}

	virtual float area()
	{
		float p = (_fa + _fb + _fc) / 2;
		return sqrt(p * (p - _fa) * (p - _fb) * (p - _fc));
	}
private:
	float _fa;
	float _fb;
	float _fc;

};

void display(Figure & fig)
{
	fig.display();
	cout << fig.area() << endl;
}

int main(void)
{
	Circle circle(10);
	Rectangle rectangle(3, 4);
	Triangle triangle(3, 4, 5);

	display(circle);
	display(rectangle);
	display(triangle);

	return 0;
}
