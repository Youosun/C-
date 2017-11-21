#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

template <typename Container>
void display(const Container & c)
{
	typename Container::const_iterator cit;//typename不可少
	for(cit = c.cbegin(); cit != c.cend(); ++cit)
	{
		cout << *cit << " ";
	}
	cout << endl;
}

void test0()
{
	vector<int> vecInt{1, 2, 3, 4, 5, 6};
	display(vecInt);

	vector<int>::iterator it = vecInt.end();
	vecInt.insert(it, 7);
	display(vecInt);

	it = vecInt.begin();
	vecInt.insert(it, 0);//在vector的头部可以插入元素，但不推荐  开销很大  需要将后面所有的元素向后挪动一位
	display(vecInt);
	cout << endl;

	deque<int> dequeInt(vecInt.begin(), vecInt.end());//使用vector的头尾迭代器进行初始化
	display(dequeInt);

	deque<int>::iterator dit = dequeInt.begin();
	++dit;
	dit = dequeInt.insert(dit, 8);//对于deque来说，insert()方法的时间复杂度与元素的个数正相关为O(N)
	display(dequeInt);

	int arr[3] = {10, 11, 12};
	dequeInt.insert(dit, arr, arr + 3);//对于原生指针也能进行容器的初始化和插入操作
	display(dequeInt);
	cout << "----list" << endl;

	list<int> listInt{1, 2, 3, 4, 5, 6, 7, 8};
	list<int>::iterator lit = listInt.begin();
	++lit;
	cout << "display list = " << endl;
	display(listInt);

	listInt.insert(lit, 7);//时间复杂度O(1)，位置确定
	cout << "display list = " << endl;
	display(listInt);

	cout << "after clear() = " << endl;
	listInt.clear();
	display(listInt);

	vecInt.clear();//对于vector而言，clear()只清空元素，并不回收空间
	cout << "vector's cap = " << vecInt.capacity() << endl;//capacity()方法是vector所独有的
	cout << "vector's size = " << vecInt.size() << endl;
}

int main(void)
{
	test0();

	return 0;
}
