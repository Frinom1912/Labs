#pragma once
#include "headers.h"

class Planet
{
public:
	static void sortName(Planet* object, const int& objectCount);
	static Planet* ReadBase(const char* fileName, Planet* object, int& objectCount);
	static void WriteBase(const char* fileName, const Planet* object, const int& objectCount);
	static Planet* EditBase(Planet* object, int& objectCount);
	Planet();
	Planet(const Planet& object);
	~Planet();
	Planet& operator=(const Planet& object);
	friend std::ostream& operator<<(std::ostream& out, const Planet& object);
	friend std::ofstream& operator<<(std::ofstream& out, const Planet& object);
	friend std::ifstream& operator>>(std::ifstream& in, Planet& object);
	friend std::istream& operator>>(std::istream& in, Planet& object);
	friend bool operator>(const Planet& object1, const Planet& object2);
private:
	char* name;
	int name_size;
	int diameter;
	int satellite;
	bool population;

	void editName(char*);

	static Planet* resize(Planet* object, int& arr_size, const int& num_of_resize);
	static int toInt(const char* arr);
	static int length(char* arr);
};
