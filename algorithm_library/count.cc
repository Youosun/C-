#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
	std::vector<int> v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

	int target1 = 3;
	int target2 = 5;

	int num_item1 = std::count(v.begin(), v.end(), target1);
	int num_item2 = std::count(v.begin(), v.end(), target2);

	std::cout << "number = " << target1 << "count = " << num_item1 << std::endl;
	std::cout << "number = " << target2 << "count = " << num_item2 << std::endl;

	int num_item3 = std::count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});
	std::cout << "number divisible by three : " << num_item3 << std::endl;

	return 0;
}
