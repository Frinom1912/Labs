#pragma once
#include <iostream>

const int MAX_SIZE = 5;

class MyVector
{
public:
	MyVector(const char* el = NULL, int maxsz = MAX_SIZE);

	MyVector(MyVector& v);
	~MyVector();

	void add_element(const char* el);
	bool delete_element(int i);
	char* operator[](int i);

	void sort();

	int find(const char* el);
	MyVector& operator=(MyVector& v);
	friend std::ostream& operator<<(std::ostream& out, MyVector& v);

protected:
	int maxsize;
	int size;
	char** arr;

private:
	void resize();
	static int length(const char* arr);
};
