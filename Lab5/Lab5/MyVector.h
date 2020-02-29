#pragma once
#include <iostream>
const int MAX_SIZE = 5;

class MyVectorChar
{
public:
	MyVectorChar(const char* el = 0, int maxsz = MAX_SIZE);
	MyVectorChar(MyVectorChar& v);
	~MyVectorChar();

	void add_element(const char* el);
	bool delete_element(int i);
	char* operator[](int i);

	void sort();

	int find(const char* el);
	MyVectorChar& operator=(MyVectorChar& v);
	friend std::ostream& operator<<(std::ostream& out, MyVectorChar& v);

protected:
	int maxsize;
	int size;
	char** arr;

	static int length(const char* arr);

private:
	void resize();
};
