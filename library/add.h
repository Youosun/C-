#ifndef __CPP_ADD_H__
#define __CPP_ADD_H__
template <typename T> //模板声明
T add(T,T);

#include "add.cc"    //在头文件最后include 模板函数的实现
					//C++头文件的模板声明与实现不能分离  
					// 因为函数模板的声明并不产生任何的函数定义
					//否则需要在头文件末尾添加实现文件
#endif
