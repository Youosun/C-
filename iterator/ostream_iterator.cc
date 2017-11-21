#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void)
{
//	cout << "sizeof(cout) = " << sizeof(cout) << endl;
	ostream_iterator<int> osi(cout, " ");

	vector<int> nums{1, 2, 3, 4, 5, 6};
	
	copy(nums.begin(), nums.end(), osi);
	cout << endl;

	return 0;
}
