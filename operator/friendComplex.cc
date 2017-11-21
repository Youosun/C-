#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double real = 0.0, double image = 0.0)
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

	//符合运算符的重载推荐以成员函数形式进行 += ++ --
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimage += rhs._dimage;
		return *this;
	}

	//前置++ 返回*this 相较于后置++  效率更高
	Complex & operator++() //前置++ 往往返回&
	{
		++_dreal;
		++_dimage;
		return *this;
	}

	Complex operator++(int)//用带参int来区分后置++ 
	{
		Complex temp(*this);//后置++ 返回新构造的temp对象
		++_dreal;
		++_dimage;
		return temp;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs); //操作符+ 的重载实现可以通过+=来实现
private:
	double _dreal;
	double _dimage;
};

//	Complex operator+(const Complex & lhs, const Complex & rhs)
//	{
//		return Complex(lhs._dreal + rhs._dreal,
//						lhs._dimage + rhs._dimage);
//	}

Complex operator+(const Complex & lhs, const Complex & rhs)
{
	Complex temp(lhs);
	temp += rhs;
	return temp;
}
int main(void)
{
	Complex c1(1, 2);
	//++c1;
	c1.print();

	Complex c2 = c1 + 5;
	//c2++;
	c2.print();

	Complex c3 = 5 + c1;
	c3.print();

	return 0;
}
