#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

//remove-erase惯用法
//遍历容器的过程中  不建议做删除或添加元素的操作
//可能导致迭代器失效
int test(void)
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	vec[3] = vec[5] = vec[7] = 99;

	vec.erase(std::remove(vec.begin(), vec.end(), 99), vec.end());
//	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	auto it = std::remove(vec.begin(), vec.end(), 99);
//	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	vec.erase(it, vec.end());
//	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
//	cout << endl;

	return 0;
}

void test1()
{
	vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	vec[3] = vec[5] = vec[7] = 99;

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout <<endl;

	vec.erase(std::remove(vec.begin(), vec.end(), 99), vec.end());
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
	cout <<endl;
}

void test2()
{
	vector<string> vec;
	vec.push_back("This is 1st sentence");

	bool flag = true;
	for(auto it = vec.begin(); it != vec.end(); ++it)//在遍历元素的同时不要进行修改
	{												// 否则容易造成迭代器失效的问题
		cout << *it << endl;						//原因：修改元素造成容器capacity增大  原来迭代器指向失效位置
		if(flag)
		{
			vec.push_back("This is 2nd sentence");  //容器在这里扩容
			flag = false;
		}
	}

}

int main(void)
{
//	test1();
	test2();

	return 0;
}
