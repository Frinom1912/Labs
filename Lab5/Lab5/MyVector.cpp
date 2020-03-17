#include "MyVector.h"
//////////// Char ////////////////
//MyVectorChar::MyVectorChar(const char* el, int maxsz)
//{
//	maxsize = maxsz;
//	size = 0;
//	arr = new char* [maxsize];
//	if (el != NULL)
//	{
//		size++;
//		int elSize = length(el);
//		for (int i = 0; i < size; i++)
//			arr[i] = new char[elSize];
//		for (int i = 0; i < elSize; i++)
//			arr[0][i] = el[i];
//	}
//}
//
////MyVectorChar::MyVectorChar(MyVectorChar& v)
//{
//	this->operator=(v);
//}
//
//MyVectorChar::~MyVectorChar()
//{
	/*for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;*/
//}
//
//void MyVectorChar::add_element(const char* el)
//{
//	resize();
//	arr[size] = new char[length(el)];
//	for (int i = 0; i < length(el); i++)
//		arr[size][i] = el[i];
//	size++;
//	sort();
//}
//
//bool MyVectorChar::delete_element(int i)
//{
//	resize();
//	for (int j = 0; j < size-1; j++)
//	{
//		if (j >= i)
//		{
//			arr[j] = arr[j + 1];
//		}
//	}
//	size--;
//	sort();
//	return true;
//}
//
//char* MyVectorChar::operator[](int i)
//{
//	return arr[i];
//}
//
//void MyVectorChar::sort()
//{	
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//		{
//			if (strcmp(arr[i], arr[j]) > 0)
//			{
//				char* temp = new char[length(arr[i])];
//
//				for (int k = 0; k < length(arr[i]); k++)
//					temp[k] = arr[i][k];
//				arr[i] = arr[j];
//				arr[j] = temp;
//				temp = nullptr;
//			}
//		}
//	}
//}
//
//int MyVectorChar::find(const char* el)
//{
//	int mid = size/2, right=size, left=0;
//	int prevMid = -1;
//	while (true)
//	{
//		if (strcmp(el, arr[mid]) > 0)
//		{
//			left = mid;
//			mid = (right + left) / 2;
//		}
//		else
//		{
//			if (strcmp(el, arr[mid]) < 0)
//			{
//				right = mid;
//				mid = (right + left) / 2;
//			}
//			else
//				return mid;
//		}
//		if (prevMid == mid)
//			break;
//		prevMid = mid;
//	}
//	return -1;
//}
//
//MyVectorChar& MyVectorChar::operator=(MyVectorChar& v)
//{
//	maxsize = v.maxsize;
//	size = v.size;
//	arr = new char* [maxsize];
//	for (int i = 0; i < size; i++)
//		arr[i] = new char[length(v.arr[i])];
//	for (int i = 0; i < size; i++)
//	{
//		int j = 0;
//		for (; v.arr[i][j] != '\0'; j++)
//		{
//			arr[i][j] = v.arr[i][j];
//		}
//		arr[i][j] = '\0';
//	}
//	return *this;
//}
//
//void MyVectorChar::resize()
//{
//	int tempSize;
//	if (size + 1 > maxsize)
//	{
//		tempSize = (int)(1.5 * maxsize);
//	}
//	else
//	{
//		if (size - 1 < maxsize / 2)
//		{
//			tempSize = (int)(2 * maxsize / 3);
//		}
//		else
//			tempSize = maxsize;
//	}
//	char** temp = new char* [tempSize];
//	for (int i = 0; i < size; i++)
//		temp[i] = new char[length(this->arr[i])];
//	for (int i = 0; i < size; i++)
//	{
//		int j = 0;
//		for (; arr[i][j] != '\0'; j++)
//			temp[i][j] = arr[i][j];
//		temp[i][j] = '\0';
//	}
//	delete[] arr;
//	arr = temp;
//	maxsize = tempSize;
//}
//
//int MyVectorChar::length(const char* arr)
//{
//	int i = 0; 
//	for (; arr[i] != '\0'; i++);
//	return i+1;
//}
//
//std::ostream& operator<<(std::ostream& out, MyVectorChar& v)
//{
//	for (int i = 0; i < v.size; i++)
//		out << v[i] << " ";
//	return out;
//}