#include <iostream>
#include <limits>
using namespace std;

int main(void)
{
	int val;

	while(cin >> val,!cin.eof())  //输入结束符ctrl + d  ---> EOF
	{
		if(cin.bad())
		{
			cout << "io corrupted!" << endl;
			return -1;
		}
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Input error  Pls input again:" << endl;
			continue;
		}
		cout << "val = " << val << endl;
	}

	return 0;
}

