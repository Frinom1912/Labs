#include "stdafx.h"

bool MySet::operator==(MySet& s)
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

MySet& MySet::operator+=(MySet& s)
{
	for (int i = 0; i < s.size; i++)
		this->add_element(s[i]);
	return *this;
}

MySet& MySet::operator-=(MySet& s)
{
	for (int i = 0; i < size; i++)
	{
		if (s.is_element(this->arr[i]))
			this->delete_element(arr[i]);
	}
	return *this;
}

MySet& MySet::operator*=(MySet& s)
{
	for (int i = 0; i < size; i++)
	{
		if (!s.is_element(this->arr[i]))
			this->delete_element(arr[i]);
	}
	return *this;
}

void MySet::add_element(const char* el)
{
	if (size == 0 || !is_element(el))
	{
		MyVector::add_element(el);
	}
}

void MySet::delete_element(const char* el)
{
	if (find(el) != -1)
	{
		MyVector::delete_element(find(el));
	}
}

bool MySet::is_element(const char* el)
{
	return find(el) == -1 ? false : true;
}

std::ostream& operator<<(std::ostream& out, MySet& s)
{
	out << "{ ";
	for (int i = 0; i < s.size; i++)
		out << s[i] << " ";
	out << "}";
	return out;
}

MySet operator+(MySet& s1, MySet& s2)
{
	MySet temp;
	for (int i = 0; i < s1.size; i++)
		temp.add_element(s1[i]);
	for (int i = 0; i < s2.size; i++)
		temp.add_element(s2[i]);
	return temp;
}

MySet operator-(MySet& s1, MySet& s2)
{	
	MySet temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (!s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}

MySet operator*(MySet& s1, MySet& s2)
{
	MySet temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}
