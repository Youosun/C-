#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
	vector<int> nums{1, 2, 3, 4, 5, 6, 7};

	std::less<int> lt;
	//lt(lhs, rhs);

	replace_if(nums.begin(), nums.end(), std::bind1st(lt, 3), 7);

	std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(cout, " "));

	return 0;
}
