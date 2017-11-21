#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int test0()
{
	ifstream ifs("ifstream.txt");
	if(!ifs.good())
	{
		cout << "ifstream open file error!" << endl;
		return -1;
	}

	vector<string> lines;
	string line;
	while(getline(ifs, line)) //从文件输入流中获取每一行  放入line中  并不包含每一行的换行符
	{
	//	cout << line << endl;
		lines.push_back(line);
	}

	for(size_t idx = 0; idx != lines.size(); ++idx)
	{
		cout << lines[idx] << endl;  //需要自己加上endl
	}

	ifs.close();// 流使用结束之后记得关闭

	return 0;
}

int test1()
{
	//ate  输入流读取文件时偏移量到文件末尾
	ifstream ifs("ifstream.txt", std::ios::ate);
	if(!ifs.good())
	{
		cout << "ifs open file error" << endl;
		ifs.close();
		return -1;
	}

	cout << ifs.tellg() << endl;
	ifs.close();

	return 0;
}

int test_0()
{
	ifstream ifs("io1.cc");
	if(!ifs.good())  //常用的流打开是否成功的判断语句
	{
		cout << "ifsteam open file corrupted!" << endl;
		ifs.close();
		return -1;
	}

	ofstream ofs("ofstream.txt");
	if(!ofs.good())
	{
		cout << "ofstream open file error " << endl;
		ofs.close();
		return -1;
	}

	string line;
	while(getline(ifs, line))
	{
		ofs << line << endl;
	}
	ofs.close();

	cout << "-----" << endl;

	return 0;
}

void test_1()
{
	//app只对输出流起作用  使用ofs输出到文件流中时  附加到文件末尾
	ofstream ofs("ofstream.txt", std::ios::app);
	if(!ofs.good())
	{
		cout << "ofs open file error" << endl;
		ofs.close();
		return;
	}

	cout << ofs.tellp() << endl;
	ofs << "This line appended" << endl;
	ofs.close();
}

int main(void)
{
//	test0();
//	test1();

	test_1();
	return 0;
}
