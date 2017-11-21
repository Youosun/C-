#ifndef __CPP_NESTCLASS_H__
#define __CPP_NESTCLASS_H__

#include <iostream>
using namespace std;

//PIMPL设计模式
//1. 实现信息隐藏
//2. 只要接口稳定，内部实现做任何的变化，都不会影响到使用该文件的程序
//3. 可以以最小的代价做到平滑升级库的目的
//4. 减少编译的依赖

class Line
{
	class LineImpl;
public:
	Line(int,int,int,int);
	~Line();
	void printLine() const;
private:
	LineImpl * _pImpl; //point to Implement--PIMPL
};

#endif
