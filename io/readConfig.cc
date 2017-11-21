#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void test0()
{
	int val1 = 512;
	int val2 = 1024;
	stringstream ss;

	ss << "val= " << val1 << "val2= " << val2;  //将键值对输入到stringstream中时  注意分隔符的使用 防止读取时出错

	string s = ss.str();
	cout << s << endl;

	int num;
	while(!ss.eof())
	{
		ss >> s >> num;
		cout << "str: " << s << endl
			 << "num: " << num << endl;
	}
}

void readConfig(const string & filename)
{
	ifstream ifs(filename.c_str());  //ifs使用C类型的字符串作为打开的文件名 
									//或者使用-std=c++11
	if(!ifs.good())
	{
		cout << "ifs open file error " << endl;
		ifs.close();
		return;
	}

	string line;
	string key;
	string value;
	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << "-->" << value << endl;
	}
}

inline string int2str(int num)
{
	ostringstream oss;
	oss << num;
	return oss.str();
}

void test1()
{
	int val = 1111;
	cout << int2str(val) << endl;

	char buff[16] = {0};
	sprintf(buff,"val = %d\n",val);
	cout << buff;

}

int main(void)
{
//	test0();
	test1();
//	readConfig("Config.txt");

	return 0;
}
