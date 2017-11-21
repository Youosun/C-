#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

void test0(void)
{
	vector<int> v{3, 1, 4, 1, 5, 9};
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	if(!std::is_heap(v.begin(), v.end()))
	{
		cout << "making heap..." << endl;
		std::make_heap(v.begin(), v.end());
	}

	cout << "after make_heap, v: ";
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int> v{3, 1, 4, 1, 5, 9};
	std::make_heap(v.begin(), v.end());

	v.push_back(2);
	v.push_back(6);

	auto heap_end = std::is_heap_until(v.begin(), v.end());

	cout << "all of v : ";
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "only heap: ";
	for(auto i = v.begin(); i != heap_end; ++i)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int main(void)
{
	test1();

	return 0;
}
