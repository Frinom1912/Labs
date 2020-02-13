#pragma once
#include "headers.h"

class Planet
{
public:
	
	Planet();
	Planet& operator=(const Planet& object);
	friend std::ostream& operator<<(std::ostream& out, const Planet& object);
	friend std::ofstream& operator<<(std::ofstream& out, const Planet& object);
	friend std::ifstream& operator>>(std::ifstream& in, Planet& object);
private:
	char* name;
	int name_size;
	int diameter;
	int satellite;
	int population;
};
