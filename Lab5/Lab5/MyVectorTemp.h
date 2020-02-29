#pragma once
#include <iostream>

template <class INFO> class MyVector;

template <class INFO>
std::ostream& operator<<(std::ostream& out, const MyVector<INFO> v);

template<class INFO>
class MyVector
{
public:
	MyVector(const INFO el = NULL, int maxsz = 5);
	MyVector(MyVector<INFO>& v);
	~MyVector();

	void add_element(const INFO& el);
	bool delete_element(int i);
	INFO operator[](int i);

	void sort();

	int find(const INFO& el);
	MyVector<INFO>& operator=(MyVector<INFO>& v);
	friend std::ostream& operator<<<INFO>(std::ostream& out, const MyVector<INFO> v);

protected:
	int maxsize;
	int size;
	INFO* arr;

private:
	void resize();	
};

template<class INFO>
MyVector<INFO>::MyVector(const INFO el, int maxsz)
{
	maxsize = maxsz;
	size = 0;
	arr = new INFO[maxsize];
	if (el != NULL)
	{
		size++;
		arr[0] = el;
	}
}

template<class INFO>
MyVector<INFO>::MyVector(MyVector<INFO>& v)
{
	this->operator=(v);
}

template<class INFO>
MyVector<INFO>::~MyVector()
{
	delete[] arr;
}

template<class INFO>
void MyVector<INFO>::add_element(const INFO& el)
{
	resize();
	arr[size] = el;
	size++;
	sort();
}

template<class INFO>
bool MyVector<INFO>::delete_element(int i)
{
	resize();
	for (int j = 0; j < size - 1; j++)
	{
		if (j >= i)
		{
			arr[j] = arr[j + 1];
		}
	}
	size--;
	sort();
	return true;
}

template<class INFO>
INFO MyVector<INFO>::operator[](int i)
{
	return arr[i];
}

template<class INFO>
void MyVector<INFO>::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				INFO temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<class INFO>
int MyVector<INFO>::find(const INFO& el)
{
	int mid = size / 2, right = size, left = 0;
	int prevMid = -1;
	while (true)
	{
		if (el - arr[mid] > 0)
		{
			left = mid;
			mid = (right + left) / 2;
		}
		else
		{
			if (el - arr[mid] < 0)
			{
				right = mid;
				mid = (right + left) / 2;
			}
			else
				return mid;
		}
		if (prevMid == mid)
			break;
		prevMid = mid;
	}
	return -1;
}

template<class INFO>
MyVector<INFO>& MyVector<INFO>::operator=(MyVector<INFO>& v)
{
	maxsize = v.maxsize;
	size = v.size;
	arr = new INFO[maxsize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = v.arr[i];
	}
	return *this;
}

template<class INFO>
void MyVector<INFO>::resize()
{
	int tempSize;
	if (size + 1 > maxsize)
	{
		tempSize = (int)(1.5 * maxsize);
	}
	else
	{
		if (size - 1 < maxsize / 2)
		{
			tempSize = (int)(2 * maxsize / 3);
		}
		else
			tempSize = maxsize;
	}
	INFO* temp = new INFO[tempSize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	maxsize = tempSize;
}

template <class INFO>
std::ostream& operator<<(std::ostream& out, const MyVector<INFO> v)
{
	for (int i = 0; i < v.size; i++)
		out << v.arr[i] << " ";
	return out;
};