#include <iostream>
#include <map>
#include <string>
using namespace std;

void test0()
{
	multimap<int, string> multimapIntStr{
		pair<int, string>(9, "Asia"),
		pair<int, string>(4, "Africa"),
		pair<int, string>(1, "Euro"),
		std::make_pair(4, "America")
	};
	
	multimap<int, string>::const_iterator it;
	for(it = multimapIntStr.begin(); it != multimapIntStr.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}

//	cout << multimapIntStr[1] << endl; //multimap不支持下标访问运算符
}

int main(void)
{
	test0();

	return 0;
}
