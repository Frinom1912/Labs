#pragma once
#include "headers.h"

class Planet
{
public:
	void editName(char*);
	void editDiameter(int&);
	void editSatellite(int&);
	void editPopulation(int&);
	static void sortName(Planet*, const int&);
	static Planet* ReadBase(const char*, Planet*, int&);
	static void WriteBase(const char*, const Planet*, const int&);
	static Planet* EditBase(Planet*, int&);
	Planet();
	Planet(const Planet& object);
	~Planet();
	Planet& operator=(const Planet& object);
	friend std::ostream& operator<<(std::ostream& out, const Planet& object);
	friend std::ofstream& operator<<(std::ofstream& out, const Planet& object);
	friend std::ifstream& operator>>(std::ifstream& in, Planet& object);
	friend std::istream& operator>>(std::istream& in, Planet& object);
private:
	char* name;
	int name_size;
	int diameter;
	int satellite;
	int population;

	char* strCopy(char* arr1, char* arr2);
	int length(char* arr);
};
