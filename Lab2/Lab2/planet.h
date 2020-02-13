#pragma once
#include "headers.h"

class Planet
{
public:
	static int ID;
	friend std::ofstream& operator<<(std::ofstream& out, const Planet& object);
	Planet();
	//Planet(const Planet& object2);
	//Planet(Planet&& object2);
	Planet& operator=(const Planet& object);
	friend std::ifstream& operator>>(std::ifstream& in, Planet& object);
private:
	char* name;
	int name_size;
	int diameter;
	int satellite;
	int population;
};
