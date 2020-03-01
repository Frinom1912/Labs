#pragma once
#include "MyVectorTemp.h"

template <class INFO> class MySet;

template <class INFO>
std::ostream& operator<<(std::ostream& out, MySet<INFO>& s);

template <class INFO>
MySet<INFO> operator+(MySet<INFO>& s1, MySet<INFO>& s2);

template <class INFO>
MySet<INFO> operator-(MySet<INFO>& s1, MySet<INFO>& s2);

template <class INFO>
MySet<INFO> operator*(MySet<INFO>& s1, MySet<INFO>& s2);

template<class INFO>
class MySet : public MyVector<INFO>
{
public:
	MySet(const INFO& el = NULL) : MyVector<INFO>(el) {};
	MySet(const MySet<INFO>& obj);

	friend std::ostream& operator<< <INFO>(std::ostream& out, MySet<INFO>& s);
	friend MySet<INFO> operator+ <INFO>(MySet<INFO>& s1, MySet<INFO>& s2);
	friend MySet<INFO> operator- <INFO>(MySet<INFO>& s1, MySet<INFO>& s2);
	friend MySet<INFO> operator* <INFO>(MySet<INFO>& s1, MySet<INFO>& s2);

	MySet<INFO>& operator=(const MySet<INFO>& v);
	bool operator==(MySet<INFO>& s);
	MySet<INFO>& operator+=(MySet<INFO>& s);
	MySet<INFO>& operator-=(MySet<INFO>& s);
	MySet<INFO>& operator*=(MySet<INFO>& s);
	void add_element(const INFO& el);
	void delete_element(const INFO& el);
	bool is_element(const INFO& el);
};

template <class INFO>
MySet<INFO>::MySet(const MySet<INFO>& obj)
{
	this->operator=(obj);
}

template <class INFO>
MySet<INFO>& MySet<INFO>::operator=(const MySet<INFO>& v)
{
	this->maxsize = v.maxsize;
	this->size = v.size;
	if (this->arr != nullptr)
		delete[] this->arr;
	this->arr = new INFO[this->maxsize];
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = v.arr[i];
	}
	return *this;
}

template <class INFO>
bool MySet<INFO>::operator==(MySet<INFO>& s)
{
	if (this->size == s.size)
	{
		int i = 0;
		for (; i < this->size; i++)
		{
			if (this->arr[i] != s.arr[i])
				return false;
		}
		if (i == this->size)
			return true;
	}
	else
		return false;
}

template <class INFO>
MySet<INFO>& MySet<INFO>::operator+=(MySet<INFO>& s)
{
	for (int i = 0; i < s.size; i++)
		this->add_element(s[i]);
	return *this;
}

template <class INFO>
MySet<INFO>& MySet<INFO>::operator-=(MySet<INFO>& s)
{
	for (int i = 0; i < this->size;)
	{
		if (s.is_element(this->arr[i]))
		{
			this->delete_element(this->arr[i]);
		}
		else
			i++;
	}
	return *this;
}

template <class INFO>
MySet<INFO>& MySet<INFO>::operator*=(MySet<INFO>& s)
{
	for (int i = 0; i < this->size; i++)
	{
		if (!s.is_element(this->arr[i]))
			this->delete_element(this->arr[i]);
	}
	return *this;
}

template <class INFO>
void MySet<INFO>::add_element(const INFO& el)
{
	if (this->size == 0 || !is_element(el))
	{
		MyVector<INFO>::add_element(el);
	}
}

template <class INFO>
void MySet<INFO>::delete_element(const INFO& el)
{
	if (this->find(el) != -1)
	{
		MyVector<INFO>::delete_element(find(el));
	}
}

template <class INFO>
bool MySet<INFO>::is_element(const INFO& el)
{
	return this->find(el) == -1 ? false : true;
}

template <class INFO>
std::ostream& operator<<(std::ostream& out, MySet<INFO>& s)
{
	out << "{";
	for (int i = 0; i < s.size; i++)
		out << s[i] << ((i == s.size - 1) ? "" : " , ");
	out << "}";
	return out;
}

template <class INFO>
MySet<INFO> operator+(MySet<INFO>& s1, MySet<INFO>& s2)
{
	MySet<INFO> temp;
	for (int i = 0; i < s1.size; i++)
		temp.add_element(s1[i]);
	for (int i = 0; i < s2.size; i++)
		temp.add_element(s2[i]);
	return temp;
}

template <class INFO>
MySet<INFO> operator-(MySet<INFO>& s1, MySet<INFO>& s2)
{
	MySet<INFO> temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (!s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}

template <class INFO>
MySet<INFO> operator*(MySet<INFO>& s1, MySet<INFO>& s2)
{
	MySet<INFO> temp;
	for (int i = 0; i < s1.size; i++)
	{
		if (s2.is_element(s1[i]))
			temp.add_element(s1[i]);
	}
	return temp;
}
