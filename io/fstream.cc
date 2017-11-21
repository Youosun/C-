#include <iostream>
#include <fstream>
using namespace std;

int test()
{
	fstream fs("fs.txt");//要求文件存在    每次打开文件文件偏移量都会清空原有文件
	if(!fs.good())
	{
		cout << "fs open file error " << endl;
		fs.close();
		return -1;
	}

	int num;

	for(size_t idx = 0; idx != 10; ++idx)//输入流输入结束之后 文件偏移量在文件末尾
	{
		cin >> num;
		fs << num << " ";
	}

	//fs.seekg(0,std::ios::beg); //将文件偏移量重置到文件开始位置 iG
	fs.seekp(0,std::ios::beg); //将文件偏移量重置到文件开始位置	oP   对于fs流都可以
	

	for(size_t idx = 0; idx != 10; ++idx)
	{
		fs >> num;
		cout << num << " ";
	}

	fs.close();

	return 0;
}

int main(void)
{
	test();

	return 0;
}
