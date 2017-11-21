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

	//后置++
	Complex operator++(int)//用带参int来区分后置++ 
	{
		Complex temp(*this);//后置++ 返回新构造的temp对象
		++_dreal;
		++_dimage;
		return temp;
	}
	//输入输出运算符重载函数要求第一个参数是流类型(ostream,istream)
	//而如果作为类的成员函数出现，则第一个参数是代表对象本身的this指针
	//故  输入输出运算符的重载函数不能是类的成员函数
	//operator<<()

	friend Complex operator+(const Complex & lhs, const Complex & rhs); //操作符+ 的重载实现可以通过+=来实现


	//流对象本身不能复制 ，返回值只能是引用
	friend std::ostream & operator<<(std::ostream & os, const Complex & rhs);
	friend std::istream & operator>>(std::istream & is, Complex & rhs);
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

std::ostream & operator<<(std::ostream & os, const Complex & rhs)
{
	os << rhs. _dreal;
	if(rhs._dimage != 0)
	{
		if(rhs._dimage > 0)
		{
			os << " + " << rhs._dimage << "i";
		}else {
			os << " - " << (-1)* rhs._dimage << "i";
		}
	}
	return os;
}

std::istream & operator>>(std::istream & is, Complex & rhs)
{
	is >> rhs._dreal;

	while(is.get() != '*');//如果读取到的字符不是*  则循环读入----以*作为分隔符

	is >> rhs._dimage;

	return is;
}

int main(void)
{
	Complex c1(1, 2);
	//++c1;
	//c1.print();
	cout << "c1 =" << c1 << endl;

	Complex c2 = c1 + 5;//存在隐式类型转换 
	//c2++;
	c2.print();

	cin >> c2;
	cout << "c2 =" << c2 << endl;

//	Complex c3 = 5 + c1;
//	c3.print();

	return 0;
}
