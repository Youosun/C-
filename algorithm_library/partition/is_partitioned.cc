#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void)
{
	array<int, 9> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto is_even = [](int i){
		return i % 2 == 0;
	};

	cout.setf(std::ios_base::boolalpha);
	cout << std::is_partitioned(v.begin(), v.end(), is_even) << endl;
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	std::partition(v.begin(), v.end(), is_even);
	cout << std::is_partitioned(v.begin(), v.end(), is_even) << endl;
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	std::reverse(v.begin(), v.end());
	cout << std::is_partitioned(v.begin(), v.end(), is_even);
	for(auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
