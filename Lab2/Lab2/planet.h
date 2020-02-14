#pragma once
#include "headers.h"

class Planet
{
public:
	void editName(char*);
	void editDiameter(int&);
	void editSatellite(int&);
	void editPopulation(int&);
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
};
