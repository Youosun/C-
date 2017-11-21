#include <math.h> //C的头文件

#include <iostream>//C++的头文件
using std::endl;
using std::cout;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	//友元之外部普通函数(自由函数)
	friend float distance(const Point & lhs, const Point & rhs); 
private:
	int _ix;
	int _iy;
};

float distance(const Point & pt1, const Point & pt2)  //distance函数的实现与std冲突  故不能使用using namespace std; 错误出现复杂
{
	return sqrt((pt1._ix - pt2._ix) * (pt1._ix - pt2._ix) + (pt1._iy - pt2._iy) * (pt1._iy - pt2._iy));
}

int main(void)
{
	Point p1(1, 2);
	Point p2(2, 4);

	p1.print();
	p2.print();

	float res = distance(p1, p2);

	cout << "distance= " << res << endl;

	return 0;
}
