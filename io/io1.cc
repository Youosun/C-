#include <iostream>
#include <string>
#include <limits>

using namespace std;

void printCinStatus()
{
	cout << "cin's badbit = " << cin.bad() << endl;
	cout << "cin's failbit = " << cin.fail() << endl;
	cout << "cin's eofbit = " << cin.eof() << endl;
	cout << "cin's goodbit = " << cin.good() << endl;
}

int main(void)
{
	int num;

	printCinStatus();

	while(cin >> num)
	{
		cout << "num = " << num << endl;
	}

	printCinStatus();

	cin.clear();//修复failbit
	//cin.ignore(1024,'\n'); //清空缓冲区  直到'\n'分隔符
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	printCinStatus();

	string s;
	cin >> s;
	cout << s << endl;

	return 0;
}
