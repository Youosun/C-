#include <string.h>
#include <iostream>
using namespace std;

template <typename T>
T add(T x, T y)
{
	return x + y;
}

//1.模板特化----把所有的模板参数固定下来
template <>
char * add(char * px, char * py)
{
	char * ptemp = new char[strlen(px) + strlen(py) + 1]();
	strcpy(ptemp, px);
	strcat(ptemp, py);
	return ptemp;
}

//2.模板偏特例化 -- 把部分模板参数固定下来

int main(void)
{
	int ia = 1, ib = 2;
	double da = 3.3, db = 4.1;
	
	cout << "ia + ib = " << add(ia, ib) << endl;
	cout << "da + db = " << add<double>(da, db) << endl;

	char str1[64] = "hello world";
	char str2[] = "zhenzhou zzu";

	cout << "str = " << add(str1, str2) << endl;

	return 0;
}
