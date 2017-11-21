#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class HeapSort
{
public:
	HeapSort(vector<T> & array)
	: _array(array)
	{}

	void heapAdjust(int parent, int size);
	void sort();
	void makeHeap();

	void print() const;
private:
	vector<T> _array;
};

template <typename T>
void HeapSort<T>::heapAdjust(int parent, int size) //每一次heapAdjust只进行从parent节点到底部的调整
{
	int child = parent * 2 + 1;
	T temp = _array[parent]; //temp保存父节点的值
	while(child < size)
	{
		if(child + 1 < size && 
			_array[child] < _array[child + 1]) //如果父节点有右孩子，且左孩子小于右孩子
			++child;							//child始终保持孩子中最大的节点

		if(temp < _array[child])//父节点值小于孩子节点的最大值
		{
			_array[parent] = _array[child]; //parent保存最大值

			parent = child;					//更新parent 和child
											//向下递归进行堆调整
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
	_array[parent] = temp;  //最后进行替换
}

template <typename T>
void HeapSort<T>::makeHeap()
{
	for(int idx = _array.size() / 2 - 1; idx >= 0; --idx)
	{
		heapAdjust(idx, _array.size());
	}
}

template <typename T>
void HeapSort<T>::sort()
{
	makeHeap();
	for(int idx = _array.size() - 1; idx > 0; --idx)
	{
		std::swap(_array[0], _array[idx]);
		heapAdjust(0, idx);
	}
}

template <typename T>
void HeapSort<T>::print() const
{
	for(auto it = _array.rbegin(); it != _array.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test0()
{
	vector<int> nums{2, 3, 5, 6, 1, 8, 4, 7, 9, 0, 12, 10, 11, 14, 4, 2, 16, 24, 32, 43, 56, 23};


	HeapSort<int> hs(nums);
	hs.sort();
	hs.print();
}

int main(void)
{
	test0();

	return 0;
}
