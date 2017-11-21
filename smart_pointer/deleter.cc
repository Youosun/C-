#include <string.h>
#include <iostream>
#include <memory>
using namespace std;

//针对于特殊类型的资源(文件指针...)的RAII方式
//采用特定的deleter方式
struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout << "fclose(fp)" << endl;
		}
	}
};

void test0()
{
	unique_ptr<FILE, Fpcloser> pFileHandler(fopen("test.txt","rw+"));
	//unique_ptr智能指针  指定特殊的deleter函数

	char buff[1024];
	memset(buff, 0, sizeof(buff));
	fread(buff, 1, 1024, pFileHandler.get());
	cout << buff << endl;

	string msg = "zhengzhoudaxue";
	fwrite(msg.c_str(), 1, msg.size(), pFileHandler.get());
}

void test1()
{
	shared_ptr<FILE> sp(fopen("test.txt","rw+"), Fpcloser());
	//shared_ptr智能指针初始化方式  函数对象作为deleter函数

	char buff[1024];
	memset(buff, 0, sizeof(buff));
	fread(buff, 1, 1024, sp.get());
	cout << buff << endl;

	string msg = "zhengzhoudaxue";
	fwrite(msg.c_str(), 1, msg.size(), sp.get());
}

int main(void)
{
	test0();

	return 0;
}
