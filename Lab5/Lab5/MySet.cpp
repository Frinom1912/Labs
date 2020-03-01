#include "MySet.h"
MySetChar::MySetChar(const MySetChar& obj)
{
	this->operator=(obj);
}

MySetChar& MySetChar::operator=(const MySetChar& v)
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

bool MySetChar::operator==(MySetChar& s)
{
	if (size == s.size)
	{
		int i = 0;
		for (; i < size; i++)
		{
			if (length(arr[i]) == length(s.arr[i]))
			{
				for (int j = 0; j < length(arr[i]); j++)
				{
					if (arr[i][j] != s.arr[i][j])
						return false;
				}
			}
			else
				return false;
		}
		if (i == size)
			return true;
	}
	else
		return false;
}

MySetChar& MySetChar::operator+=(MySetChar& s)
{
	for (int i = 0; i < s.size; i++)
		this->add_element(s[i]);
	return *this;
}

MySetChar& MySetChar::operator-=(MySetChar& s)
{
	for (int i = 0; i < size;)
	{
		if (s.is_element(this->arr[i]))
		{
			this->delete_element(arr[i]);
		}
		else
			i++;
	}
	return *this;
}

MySetChar& MySetChar::operator*=(MySetChar& s)
{
	for (int i = 0; i < size; i++)
	{
		if (!s.is_element(this->arr[i]))
			this->delete_element(arr[i]);
	}
	return *this;
}

void MySetChar::add_element(const char* el)
{
	if (size == 0 || !is_element(el))
	{
		MyVectorChar::add_element(el);
	}
}

void MySetChar::delete_element(const char* el)
{
	if (find(el) != -1)
	{
		MyVectorChar::delete_element(find(el));
	}
}

bool MySetChar::is_element(const char* el)
{
	return find(el) == -1 ? false : true;
}

std::ostream& operator<<(std::ostream& out, MySetChar& s)
{
	out << "{";
	for (int i = 0; i < s.size; i++)
		out << s[i] << ((i == s.size-1) ? "" : " , ");
	out << "}";
	return out;
}

MySetChar operator+(MySetChar& s1, MySetChar& s2)
{
	MySetChar temp;
	for (int i = 0; i < s1.size; i++)
		temp.add_element(s1[i]);
	for (int i = 0; i < s2.size; i++)
		temp.add_element(s2[i]);
	return temp;
}

MySetChar operator-(MySetChar& s1, MySetChar& s2)
{	
	MySetChar temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (!s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}

MySetChar operator*(MySetChar& s1, MySetChar& s2)
{
	MySetChar temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}