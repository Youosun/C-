#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>

int main(void)
{
	std::vector<int> v(10, 2);
	std::partial_sum(v.cbegin(), v.cend(), ++v.begin());
	std::cout << "Among the nums:";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	if(std::all_of(v.cbegin(), v.cend(), [] (int i){return i % 2 ==0;})) {
		std::cout << "All nums are even" << std::endl;
	}

	return 0;
}
