#include <iostream>

using namespace std;

int main()
{
	cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;
	cout << "sizeof(char) =" << sizeof(char) << endl;

	cout << "__LINE__: 在源代码中插入当前源代码行号 = " << __LINE__ << endl;
	cout << "__FILE__: 在源文件中插入当前源文件名 = " << __FILE__ << endl;
	cout << "__DATE__: 在源文件中加入当前编译日期 = " << __DATE__ << endl;
	cout << "__TIME__: 在源文件中加入当前编译时间 = " << __TIME__ << endl;
	cout << "__FUNCTION__: 在源文件中插入函数名 = " << __FUNCTION__ << endl;

	//__STDC__:要求程序严格遵循ANSI C标准时，该标志为1
	//__cplusplus: 当编写C++程序时该标志符被定义
	
	return 0;
}
