
#include "nestClass.h"
#include <iostream>
using namespace std;

class Line::LineImpl
{
public:
	LineImpl(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "LineImpl(int,int,int,int)" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << "-->";
		_pt2.print();
		cout << endl;
	}

private:
	class Point
	{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{}

		void print() const;
	private:
		int _ix;
		int _iy;
	};
private:
	Point _pt1;
	Point _pt2;
};

void Line::LineImpl::Point::print() const
{
	cout << "(" << _ix
		 << "," << _iy
		 << ")";
}

Line::Line(int x1, int y1, int x2, int y2)
: _pImpl(new LineImpl(x1, y1, x2, y2))
{
}

Line::~Line()
{
	delete _pImpl;
}

void Line::printLine() const
{
	_pImpl->printLine();
}
