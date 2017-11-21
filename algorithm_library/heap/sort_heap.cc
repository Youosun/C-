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
	vector<int> v = {3, 1, 4, 1, 5, 9};

	std::make_heap(v.begin(), v.end());

	cout << "heap: \t";
	print(v);

	sort_heap(v.begin(), v.end()); //默认下按照升序排列

	cout << "\nsorted:\t";
	print(v);
	
	return 0;
}
