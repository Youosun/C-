#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_sig == NULL)
		{
			_sig = new Singleton();
			cout << "Get a Singleton success" << endl;
		}
		return _sig;
	}
private:
	Singleton() 
	{
		cout << "This is Singleton construtor" << endl;
	}
	static Singleton * _sig;

	class GC
	{
	public:
		GC()
		{
			cout << "GC constructor" << endl;
		}
		~GC()
		{
			cout << "GC destructor" << endl;
			if(_sig != NULL)
			{
				delete _sig;
				_sig = NULL;
				cout << "Singleton destructor" << endl;
			}
		}
	};

	static GC gc;
};

Singleton * Singleton::_sig = NULL;
Singleton::GC Singleton::gc;

int main(void)
{
	Singleton * sig = Singleton::getInstance();

	return 0;
}
