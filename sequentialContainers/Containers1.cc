#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

//vector/deque 都实现了operator[],支持随机访问。说明能在O(1)的时间内找到元素
//
//list双向链表实现  不支持operator[], 不支持随机访问，只支持双端访问

void test0()
{
	deque<int> dequeInt{1, 2, 3, 4, 5, 6};
	for(size_t idx = 0; idx != dequeInt.size(); ++idx)
	{
		cout << dequeInt[idx] << endl;//实现了下标访问运算符
	}
	cout << endl;

	//使用迭代器 进行遍历访问
	deque<int>::const_iterator cit = dequeInt.cend();
	while(cit != dequeInt.cbegin())
	{
		--cit;
		cout << *cit << endl;
	}
	cout << endl;

	list<float> listFloat(3,5); //3个元素 初始化为5
	//cout << listFloat[0] << endl; //list 是不支持下标访问运算符的
	
	list<float>::const_iterator clit;//双向访问迭代器
	for(clit = listFloat.cbegin(); clit != listFloat.cend(); ++clit)
	{
		cout << *clit << endl;
	}
}

int main(void)
{
	test0();

	return 0;
}
