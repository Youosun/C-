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

	cout << "v: " << endl;
	print(v);

	v.push_back(6);

	cout << "before push heap: ";
	print(v);

	std::push_heap(v.begin(), v.end());

	cout << "after push heap : ";
	print(v);

	return 0;
}
