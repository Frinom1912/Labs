#pragma once
#include "MyVector.h"
#include <iostream>
class MySet : public MyVector
{
public:
	MySet(const char* el = NULL) : MyVector(el) {};

	friend std::ostream& operator<<(std::ostream& out, MySet& s);
	friend MySet operator+(MySet& s1, MySet& s2);
	friend MySet operator-(MySet& s1, MySet& s2);
	friend MySet operator*(MySet& s1, MySet& s2);

	bool operator==(MySet& s);
	MySet& operator+=(MySet& s);
	MySet& operator-=(MySet& s);
	MySet& operator*=(MySet& s);
	void add_element(const char* el);
	void delete_element(const char* el);
	bool is_element(const char* el);
};
