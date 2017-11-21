#include <math.h>
#include <iostream>
#include <functional>
using namespace std;

//function | bind 模式  实现多态的另一种方式
//基于对象的编程方式
//1. 具体类, 不在是一个抽象类
//2. 其他的图形类也是与Figure无关的类
//3. 要调用的成员函数的名字可以进行灵活的变动 不需要保持一致

class Figure
{
public:
	Figure(){}

	//注册回调函数
	void setDisplayCallback(const function<void()> & cb)
	{
		_displayCallback = cb;
	}

	void setAreaCallback(const function<float()> & cb)
	{
		_areaCallback = cb;
	}

	//执行回调函数
	void handleDisplayCallback()
	{
		if(_displayCallback)
			_displayCallback();
	}

	float  handleAreaCallback()
	{
		if(_areaCallback)
			return	_areaCallback();
		else 
			return -1;
	}
private:
	function<void()> _displayCallback;
	function<float()> _areaCallback;
};

class Circle
{
public:
	Circle(float fradius)
	: _fradius(fradius)
	{}

	void showCircle() const
	{	cout << "circle : " << endl;	}

	float calArea()
	{
		return 3.1415926 * _fradius * _fradius;
	}
private:
	float _fradius;
};

class Rectangle
{
public:
	Rectangle(float flength, float fwidth)
	: _flength(flength)
	, _fwidth(fwidth)
	{}

	void showRectangle() const
	{	cout << "Rectangle : " << endl;}

	float calArea()
	{
		return _flength * _fwidth;
	}
private:
	float _flength;
	float _fwidth;
};

class Triangle
{
public:
	Triangle(float fa, float fb, float fc)
	: _fa(fa)
	, _fb(fb)
	, _fc(fc)
	{}

	void showTriangle()const
	{	cout << "Triangle : " << endl;	}

	float stasticsArea()
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
	fig.handleDisplayCallback();
	cout << fig.handleAreaCallback() << endl;
}

int main(void)
{
	Circle circle(10);
	Rectangle rectangle(3, 4);
	Triangle triangle(3, 4, 5);

	Figure fig;
	fig.setDisplayCallback(std::bind(&Circle::showCircle, &circle));
	fig.setAreaCallback(std::bind(&Circle::calArea, &circle));
	display(fig);

	fig.setDisplayCallback(std::bind(&Rectangle::showRectangle, &rectangle));
	fig.setAreaCallback(std::bind(&Rectangle::calArea, &rectangle));
	display(fig);

	fig.setDisplayCallback(bind(&Triangle::showTriangle, &triangle));
	fig.setAreaCallback(std::bind(&Triangle::stasticsArea, &triangle));
	display(fig);
	
	return 0;
}
