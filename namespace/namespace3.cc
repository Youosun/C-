#include <iostream>

using namespace std;//using编译指令   不建议使用

void cout()
{
}

int main(void)
{
	cout();//标准库std中存在于自定义函数重名的冲突 导致无法编译

	return 0;
}
