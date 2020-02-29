#pragma once
const int MAX_SIZE = 5;

class MyVectorChar
{
public:
	MyVectorChar(const char* el = NULL, int maxsz = MAX_SIZE);
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

template<class INFO>
class MyVector
{
public:
	MyVector(const INFO el = NULL, int maxsz = MAX_SIZE);
	MyVector(MyVector& v);
	~MyVector();

	void add_element(const INFO& el);
	bool delete_element(int i);
	INFO* operator[](int i);

	void sort();

	int find(const INFO& el);
	MyVector& operator=(MyVector& v);
	friend std::ostream& operator<<(std::ostream& out, MyVector& v);

protected:
	int maxsize;
	int size;
	INFO arr;

private:
	void resize();
};
