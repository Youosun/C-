#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename Container>
void print(const Container & c)
{
	for(auto it = c.begin(); it != c.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main(void)
{
	vector<int> v {3, 1, 4, 1, 5, 9};
	std::make_heap(v.begin(), v.end());

	cout << "v: ";
	print(v);

	std::pop_heap(v.begin(), v.end()); //move the largest to the end

	cout << "after pop_heap: ";
	print(v);

	int largest = v.back();
	v.pop_back();//removes the largest element
	cout << "largest element: " << largest << endl;
	
	cout << "heap without largest: ";
	print(v);

	return 0;
}
