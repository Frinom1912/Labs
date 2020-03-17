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
	MySet(const INFO el = NULL) : MyVector<INFO>(el) {};
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
	void add_element(const INFO el);
	void delete_element(const INFO el);
	bool is_element(const INFO el);

	using MyVector<INFO>::maxsize;
	using MyVector<INFO>::size;
	using MyVector<INFO>::arr;
	using MyVector<INFO>::length;
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
void MySet<INFO>::add_element(const INFO el)
{
	if (this->size == 0 || !is_element(el))
	{
		MyVector<INFO>::add_element(el);
	}
}

template <class INFO>
void MySet<INFO>::delete_element(const INFO el)
{
	if (this->find(el) != -1)
	{
		MyVector<INFO>::delete_element(find(el));
	}
}

template <class INFO>
bool MySet<INFO>::is_element(const INFO el)
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


template <unsigned N> class MySet<char[N]>;

template<unsigned N>
std::ostream& operator<<(std::ostream& out, MySet<char[N]>& s);

template<unsigned N>
MySet<char[N]> operator+(MySet<char[N]>& s1, MySet<char[N]>& s2);

template<unsigned N>
MySet<char[N]> operator-(MySet<char[N]>& s1, MySet<char[N]>& s2);

template<unsigned N>
MySet<char[N]> operator*(MySet<char[N]>& s1, MySet<char[N]>& s2);

 
class MySet<char*> : public MyVector<char*>
{
public:
	MySet(const char* el = NULL) : MyVector<char*>(el) {};
	MySet(const MySet<char*>& obj);

	friend std::ostream& operator<<(std::ostream& out, MySet<char*>& s);
	friend MySet<char*> operator+ (MySet<char*>& s1, MySet<char*>& s2);
	friend MySet<char*> operator-(MySet<char*>& s1, MySet<char*>& s2);
	friend MySet<char*> operator*(MySet<char*>& s1, MySet<char*>& s2);

	MySet<char*>& operator=(const MySet<char*>& v);
	bool operator==(MySet<char*>& s);
	MySet<char*>& operator+=(MySet<char*>& s);
	MySet<char*>& operator-=(MySet<char*>& s);
	MySet<char*>& operator*=(MySet<char*>& s);
	void add_element(const char* el);
	void delete_element(const char* el);
	bool is_element(const char* el);
	
	using MyVector<char*>::maxsize;
	using MyVector<char*>::size;
	using MyVector<char*>::arr;
	using MyVector<char*>::length;
};

 
MySet<char*>& MySet<char*>::operator=(const MySet<char*>& v)
{
	maxsize = v.maxsize;
	size = v.size;
	arr = new char*[maxsize];
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

 
bool MySet<char*>::operator==(MySet<char*>& s)
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

 
void MySet<char*>::add_element(const char* el)
{
	if (this->size == 0 || !is_element(el))
	{
		MyVector<char*>::add_element(el);
	}
}

 
void MySet<char*>::delete_element(const char* el)
{
	if (this->find(el) != -1)
	{
		MyVector<char*>::delete_element(find(el));
	}
}

 
bool MySet<char*>::is_element(const char* el)
{
	return this->find(el) == -1 ? false : true;
}

 
std::ostream& operator<<(std::ostream& out, MySet<char*>& s)
{
	out << "{";
	for (int i = 0; i < s.size; i++)
		out << s[i] << ((i == s.size - 1) ? "" : " , ");
	out << "}";
	return out;
}
