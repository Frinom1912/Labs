#pragma once
#include "headers.h"

class Planet
{
public:
	static int ID;
	std::ofstream& operator<<(std::ofstream& out);
	Planet& operator>>(std::ifstream& in);
	Planet();
	~Planet();
private:
	char* name;
	int name_size;
	int diameter;
	int satellite;
	int population;
};

int Planet::ID = 0;
