#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Sum
{
	Sum(): sum{0} {}
	void operator()(int n) { sum += n;}
	int sum;
};

int main(void)
{
	std::vector<int> nums{3, 4, 2, 8, 15, 267};
	auto print = [](const int & n){ std::cout << " " << n;};

	std::cout << "before: ";
	std::for_each(nums.begin(), nums.end(), print);
	std::cout << std::endl;

	std::for_each(nums.begin(), nums.end(), [](int & n) { ++n;}); //匿名的lambda函数表达式形式

	Sum s = std::for_each(nums.begin(), nums.end(), Sum());//functor形式  可以改变容器元素

	std::cout << "after: ";
	std::for_each(nums.begin(), nums.end(), print);//有名的lambda函数形式
	std::cout << std::endl;
	std::cout << "sum: " << s.sum << std::endl;

	return 0;
}
