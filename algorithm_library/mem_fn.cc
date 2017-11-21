#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

class Number
{
public:
	Number(int value = 0)
	: _value(value)
	{}

	void display() const
	{
		cout << _value << " ";
	}

	bool isEven() const
	{
		return !(_value % 2);
	}

	bool isPrime() const
	{
		if(_value == 1)
			return false;
		for(int idx = 2; idx <= _value / 2; ++idx)
		{
			if(!(_value % idx))
			{
				return false;
			}
		}
		return true;
	}
private:
	int _value;
};

int main(void)
{
	vector<Number> nums;
	for(int idx = 1; idx != 14; ++idx)
	{
		nums.push_back(Number(idx));
	}

	for_each(nums.begin(), nums.end(), std::mem_fn(&Number::display));
	cout << endl;

//	nums.erase(
//			std::remove_if(nums.begin(), nums.end(), std::mem_fn(&Number::isEven)),
//			nums.end()
//			);
//	for_each(nums.begin(), nums.end(), std::mem_fn(&Number::display));
//	cout << endl;

	nums.erase(
			std::remove_if(nums.begin(), nums.end(), std::mem_fn(&Number::isPrime)),
			nums.end()
			);
	for_each(nums.begin(), nums.end(), std::mem_fn(&Number::display));
	cout << endl;
	return 0;
}
