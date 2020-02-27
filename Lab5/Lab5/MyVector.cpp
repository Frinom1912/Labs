#include "MyVector.h"

MyVector::MyVector(const char* el, int maxsz)
{
	maxsize = maxsz;
	size = 1;
	int elSize = length(el);
	arr = new char* [maxsize];
	for (int i = 0; i < size; i++)
		arr[i] = new char[elSize];
	for (int i = 0; i < elSize; i++)
		arr[0][i] = el[i];
}

MyVector::MyVector(MyVector& v)
{
	this->operator=(v);
}

MyVector::~MyVector()
{
	for (int i = 0; i < maxsize; i++)
		delete[] arr[i];
	delete[] arr;
}

void MyVector::add_element(const char* el)
{
	this->resize();
	arr[size] = new char[length(el)];
	for (int i = 0; i < length(el); i++)
		arr[size][i] = el[i];
	size++;
}

bool MyVector::delete_element(int i)
{
	this->resize();
	for (int j = 0; j < size-1; j++)
	{
		if (j >= i)
		{
			arr[j] = arr[j + 1];
		}
	}
	size--;
	return true;
}

char* MyVector::operator[](int i)
{
	return arr[i];
}

void MyVector::sort()
{	
}

int MyVector::find(const char* el)
{
	return 0;
}

MyVector& MyVector::operator=(MyVector& v)
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
		arr[i][j + 1] = '\0';
	}
	return *this;
}

void MyVector::resize()
{
	int tempSize;
	if (size + 1 > maxsize)
	{
		tempSize = (int)(1.5 * maxsize);
	}
	else
	{
		if (size -1 < maxsize / 2)
		{
			tempSize = (int)(2*maxsize/3);
		}
	}
	char** temp = new char* [tempSize];
	for (int i = 0; i < size; i++)
		temp[i] = new char[length(this->arr[i])];
	for (int i = 0; i < maxsize; i++)
	{
		int j = 0;
		for (; arr[i][j] != '\0'; j++)
			temp[i][j] = arr[i][j];
		temp[i][j + 1] = '\0';
	}
	delete[] arr;
	arr = temp;
	maxsize = tempSize;
}

int MyVector::length(const char* arr)
{
	int i = 0; 
	for (; arr[i] != '\0'; i++);
	return i+1;
}

std::ostream& operator<<(std::ostream& out, MyVector& v)
{
	return out;
}
