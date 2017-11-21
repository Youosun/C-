#include <iostream>

void test()
{
	std::cout << "test()" << std::endl;
}

namespace A
{
	void displayA()
	{
		std::cout << "displayA()" << std::endl;
	}
}//end of namespace A

namespace B
{
	void displayB()
	{
		std::cout << "displayB()" << std::endl;
	}
}
//end of namespace B
//


int main(void)
{
	A::displayA();
	B::displayB();
	std::cout << "hello world" << std::endl;

	return 0;
}

