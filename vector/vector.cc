#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int> & vec)
{
	cout << "vector's size:" << vec.size() << endl;
	cout << "vector's capacity:" << vec.capacity() << endl;
}

//vector是一个动态数组  可以动态扩容
//策略：
//1、先根据当前容量扩容capacity扩展空间，开辟出2 * capacity的空间
//2、然后将原来空间中的元素全部复制到新的空间中去
//3、再在新空间的末尾添加新的元素
//4、最后回收原来的空间

int main(void)
{
	vector<int> num;
	num.reserve(50);  //提前预留空间
	size_t idx;
	for(idx = 1; idx <= 55; ++idx)
	{
		num.push_back(idx);
		printVector(num);
	}

	for(idx = 0; idx != num.size(); ++idx)
	{
		cout << num[idx] << " ";
	}

	cout << endl;

	return 0;
}
