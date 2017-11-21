 ///
 /// @file    testMylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-27 10:35:19
 ///
 
#include "Mylog.h"

#include <stdio.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cout;
using std::endl;

int test0(void)
{
	Mylog::getInstance()->debug("debug message");
	Mylog::getInstance()->error("error message");
	Mylog::getInstance()->warn("warn message");
	Mylog::getInstance()->info("info message");

	return 0;
}


int test1()
{
	printf("filename =%s, func=%s, line=%d\n",
			__FILE__, __func__, __LINE__);

	printf("hello"__FILE__"\n");
	printf("hello"
			"world\n"
			"shenzhen,wangdao\n");
	return 0;
}


int test2(void)
{
	Mylog::getInstance()->debug(prefix("debug message"));
	Mylog::getInstance()->error(prefix("error message"));
	Mylog::getInstance()->warn(prefix("warn message"));
	Mylog::getInstance()->info(prefix("info message"));

	return 0;
}

void test3()
{
	LogDebug("debug message");
	LogError("error message");
	LogWarn("warn message");
	LogInfo("info message");
}


int main(void)
{
	//test1();
	//cout << prefix("") << endl;
	//test2();
	test3();
	return 0;
}
