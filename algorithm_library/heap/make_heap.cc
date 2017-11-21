#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	std::vector<int> v {3, 1, 4, 1, 5, 9};

	cout << "initially, v: ";
	for(auto i : v) cout << i << " ";
	cout << endl;

	std::make_heap(v.begin(), v.end());

	cout << "after make_heap, v: ";
	for(auto i : v) cout << i << " ";
	cout << endl;

	std::pop_heap(v.begin(), v.end());
	auto largest = v.back();
	v.pop_back();
	cout << "largest element : " << largest << endl;

	cout << "after removing the largest element, v: ";
	for(auto i : v) cout << i << " ";
	cout << endl;

	return 0;
}
