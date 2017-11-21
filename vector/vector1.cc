#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	//int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	//vector<int> num(arr, arr + 10); // 原生指针也是一种迭代器
	//
	vector<int> num{1, 2, 3, 4, 5};

	vector<int>::iterator it;
	vector<int>::const_iterator cit;

	for(it = num.begin(); it != num.end(); ++it) //返回迭代器  可以通过迭代器改变值
	{
		++(*it);
		cout << *it << endl;
	}

	for(cit = num.cbegin(); cit != num.cend(); ++cit) //返回常量迭代器  不能通过迭代器改变值
	{
		cout << *cit << endl;
	}

	return 0;
}
