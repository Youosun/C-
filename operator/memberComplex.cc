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

	//重载操作符函数作为类成员函数 + - * / 
	Complex operator+(const Complex & rhs)
	{
		return Complex(_dreal + rhs._dreal, _dimage + rhs._dimage);
	}
private:
	double _dreal;
	double _dimage;
};

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
