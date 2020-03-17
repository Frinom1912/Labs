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

	void add_element(const INFO el);
	bool delete_element(int i);
	INFO operator[](int i);

	void sort();

	int find(const INFO el);
	MyVector<INFO>& operator=(MyVector<INFO>& v);
	friend std::ostream& operator<<<INFO>(std::ostream& out, const MyVector<INFO> v);

protected:
	int maxsize;
	int size;
	INFO* arr;
	static int length(const char* arr);
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
void MyVector<INFO>::add_element(const INFO el)
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
int MyVector<INFO>::find(const INFO el)
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

template<class INFO>
int MyVector<INFO>::length(const char* arr)
{
	int i = 0;
	for (; arr[i] != '\0'; i++);
	return i + 1;
}

template<>
class MyVector<char*>
{
public:
	MyVector(const char* el = NULL, int maxsz = 5);
	MyVector(MyVector<char*>& v);
	~MyVector();

	void add_element(const char* el);
	bool delete_element(int i);
	char* operator[](int i);

	void sort();

	int find(const char* el);
	MyVector<char*>& operator=(MyVector<char*>& v);
	friend std::ostream& operator<<(std::ostream& out, const MyVector<char*> v);

protected:
	int maxsize;
	int size;
	char** arr;
	static int length(const char* arr);
private:
	void resize();
};

 
MyVector<char*>::MyVector(const char* el, int maxsz)
{
	maxsize = maxsz;
	size = 0;
	arr = new char* [maxsize];
	if (el != NULL)
	{
		size++;
		int elSize = length(el);
		for (int i = 0; i < size; i++)
			arr[i] = new char[elSize];
		for (int i = 0; i < elSize; i++)
			arr[0][i] = el[i];
	}
}

MyVector<char*>::MyVector(MyVector<char*>& v)
{
	this->operator=(v);
}
 
MyVector<char*>::~MyVector()
{
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
}

char* MyVector<char*>::operator[](int i)
{
	return arr[i];
}

void MyVector<char*>::add_element(const char* el)
{
	resize();
	arr[size] = new char[length(el)];
	for (int i = 0; i < length(el); i++)
		arr[size][i] = el[i];
	size++;
	sort();
}

 
bool MyVector<char*>::delete_element(int i)
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

 
void MyVector<char*>::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(arr[i], arr[j]) > 0)
			{
				char* temp = new char[length(arr[i])];

				for (int k = 0; k < length(arr[i]); k++)
					temp[k] = arr[i][k];
				arr[i] = arr[j];
				arr[j] = temp;
				temp = nullptr;
			}
		}
	}
}

 
int MyVector<char*>::find(const char* el)
{
	int mid = size / 2, right = size, left = 0;
	int prevMid = -1;
	while (true)
	{
		if (strcmp(el, arr[mid]) > 0)
		{
			left = mid;
			mid = (right + left) / 2;
		}
		else
		{
			if (strcmp(el, arr[mid]) < 0)
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

 
MyVector<char*>& MyVector<char*>::operator=(MyVector<char*>& v)
{
	maxsize = v.maxsize;
	size = v.size;
	arr = new char* [maxsize];
	for (int i = 0; i < size; i++)
		arr[i] = new char[length(v.arr[i])];
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		for (; v.arr[i][j] != '\0'; j++)
		{
			arr[i][j] = v.arr[i][j];
		}
		arr[i][j] = '\0';
	}
	return *this;
}

 
void MyVector<char*>::resize()
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
	char** temp = new char* [tempSize];
	for (int i = 0; i < size; i++)
		temp[i] = new char[length(this->arr[i])];
	for (int i = 0; i < size; i++)
	{
		int j = 0;
		for (; arr[i][j] != '\0'; j++)
			temp[i][j] = arr[i][j];
		temp[i][j] = '\0';
	}
	delete[] arr;
	arr = temp;
	maxsize = tempSize;
}

std::ostream& operator<<(std::ostream& out, const MyVector<char*> v)
{
	for (int i = 0; i < v.size; i++)
		out << v.arr[i] << " ";
	return out;
};

int MyVector<char*>::length(const char* arr)
{
	int i = 0;
	for (; arr[i] != '\0'; i++);
	return i + 1;
}