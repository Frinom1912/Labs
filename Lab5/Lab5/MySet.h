#pragma once
#include "MyVector.h"
class MySetChar : public MyVectorChar
{
public:
	MySetChar(const char* el = NULL) : MyVectorChar(el) {};
	MySetChar(const MySetChar& obj);

	friend std::ostream& operator<<(std::ostream& out, MySetChar& s);
	friend MySetChar operator+(MySetChar& s1, MySetChar& s2);
	friend MySetChar operator-(MySetChar& s1, MySetChar& s2);
	friend MySetChar operator*(MySetChar& s1, MySetChar& s2);

	MySetChar& operator=(const MySetChar& v);
	bool operator==(MySetChar& s);
	MySetChar& operator+=(MySetChar& s);
	MySetChar& operator-=(MySetChar& s);
	MySetChar& operator*=(MySetChar& s);
	void add_element(const char* el);
	void delete_element(const char* el);
	bool is_element(const char* el);
};
