#include <iostream>
#include <string>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using std::cout;
using std::endl;

void test0()
{
	char s1[]="hello";
	char s2[]=",world";

	printf("s1=%s\n",s1);
	printf("s2=%s\n",s2);

	printf("sizeof(s1)=%d\n",sizeof(s1));
	printf("sizeof(s2)=%d\n",sizeof(s2));

	char * p1 = (char*) malloc(strlen(s1)+ strlen(s2) +1);//提前申请能够存放s1和s2长度的空间
	strcpy(p1, s1);
	strcat(p1,s2);
	free(p1);

//	strcat(s1,s2); //存在数组访问越界问题
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2);
}

void test1()
{
	std::string s1 = "hello"; //"hello" --> const char *
	std::string s2(",world");

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	//获取字符串的长度
	std::string s3 = s1 + s2 + "C++";
	cout<< " s3's.size() = " << s3.size() << endl;
	cout<< " s3's.length() = " << s3.length() << endl;
	cout << "s3 = " << s3 << endl;
	
	//相数组一样去访问
	for(size_t idx = 0; idx != s3.size(); ++idx)
	{
		cout << s3[idx] << endl;
	}

	//子串截取
	std::string s4 = s3.substr(6,5);
	cout << "s4 = " << s4 << endl;

	//将C++类型的字符串转换成C风格的字符串
	const char * p1 = s4.c_str();
	const char * p2 = s4.data();
	printf("p1 = %s\n",p1);
	printf("p2 = %s\n",p2);
}

int main(void)
{
	//test0();
	test1();
	return 0;
}
