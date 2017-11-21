#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Vector
{
public:
	Vector()
	: _elems(0)
	, _firstFree(0)
	, _end(0)
	{}

	~Vector()
	{
		if(_elems)
		{
			while(_firstFree != _elems)
			{
				_alloc.destroy(--_firstFree);
			}
			_alloc.deallocate(_elems, capacity());
		}
	}

	void push_back(const T & value)
	{
		if(size() == capacity())
		{
			reallocate();
		}
		_alloc.construct(_firstFree++, value);
	}

	void pop_back()
	{
		if(size() > 0)
		{
			_alloc.destroy(--_firstFree	);
		}
	}

	int size() const
	{
		return _firstFree - _elems;
	}

	int capacity() const
	{
		return _end - _elems;
	}

	const T & operator[](int idx)const
	{
		return _elems[idx];
	}
private:
	void reallocate()
	{
		int oldCapacity = capacity();
		int newCapacity = (oldCapacity != 0 ? 2 * oldCapacity : 1);

		T * newElem = _alloc.allocate(newCapacity);

		if(_elems)
		{
			std::uninitialized_copy(_elems, _firstFree, newElem);
			while(_firstFree != _elems)
			{
				_alloc.destroy(--_firstFree);
			}
			_alloc.deallocate(_elems, oldCapacity);
		}

		_elems = newElem;
		_firstFree = _elems + oldCapacity;
		_end = _elems + newCapacity;
	}
private:
	static std::allocator<T> _alloc;
	T * _elems;
	T * _firstFree;
	T * _end;
};

template <typename T>
std::allocator<T> Vector<T>::_alloc;

void display(const Vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}

void print(const Vector<int> & vec)
{
	for(int idx = 0; idx != vec.size(); ++idx)
	{
		cout << vec[idx] << " ";
	}
	cout << endl;
}

int main(void)
{
	Vector<int> vec;

	for(int idx = 0; idx != 10; ++idx)
	{
		vec.push_back(idx);
		display(vec);
	}

	print(vec);

	return 0;
}
