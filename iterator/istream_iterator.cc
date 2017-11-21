#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

void test0(void)
{
	vector<int> nums;
	istream_iterator<int> isi(cin);
//	copy(isi, istream_iterator<int>(), nums.begin());//vector<int> 此时没有空间  所以返回失败
	copy(isi, istream_iterator<int>(), std::back_inserter(nums));
	
	for(auto & elem : nums)
	{
		cout << elem << " ";
	}
	cout << endl;

#if 1
	ostream_iterator<int> osi(cout, "\n");
	copy(nums.begin(), nums.end(), osi);
#endif
}

int main(void)
{
	test0();

	return 0;
}

