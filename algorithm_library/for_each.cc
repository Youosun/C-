#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const int & value)
{
	cout << value << " ";
}

#if 0
//lambda表达式 --> 匿名函数
[capture] ( arguments ) {
   -------(function body)
}
#endif

int main(void)
{
	vector<int> nums{1, 2, 3, 4, 5, 6};

//	for_each(nums.begin(), nums.end(), display); //diaplay一元函数
												//	一般用来遍历元素

	for_each(nums.begin(), nums.end(), [](int & value){
			cout << value << " ";
			});
	return 0;
}
