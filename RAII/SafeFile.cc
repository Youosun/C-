#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class SafeFile
{
public:
	SafeFile(const string & filename)
	: _pHandler(fopen(filename.c_str(), "w+"))
	{
		cout << "SafeFile(const string &)" << endl;
	}

	SafeFile(FILE * pHandler)
	: _pHandler(pHandler)
	{
		cout << "SafeFile(FILE *) " << endl;
	}

	~SafeFile()
	{
		if(_pHandler)
		{
			fclose(_pHandler);
			cout << "~SafeFile()" << endl;
		}
	}

	void write(const string & mesg)
	{
		fwrite(mesg.c_str(), 1, mesg.size(), _pHandler);
	}
private:
	FILE * _pHandler;
};

int main(void)
{
	SafeFile sf("test.txt");

	sf.write("hello world");

	return 0;
}
