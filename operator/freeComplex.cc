#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real, double image)
	:_dreal(real)
	, _dimage(image)
	{}

	void print() const
	{
		cout << _dreal;
		if(_dimage != 0)
		{
			if(_dimage > 0)
			{
				cout << " + " << _dimage << "i";
			}else {
				cout << " - " << (-1)* _dimage << "i";
			}
		}
		cout << endl;
	}

//	Complex operator+(const Complex & rhs)
//	{
//		return Complex(_dreal + rhs._dreal, _dimage + rhs._dimage);
//	}
	friend Complex operator+(const Complex & lhs, const Complex & rhs);
private:
	double _dreal;
	double _dimage;
};

//重载的操作符函数  普通自由函数
//rhs  lhs
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
					lhs._dimage + rhs._dimage);
}

int main(void)
{
	Complex c1(1, 2);
	c1.print();

	Complex c2(2, -4);
	c2.print();

	Complex c3 = c1 + c2;

	c3.print();

	return 0;
}
