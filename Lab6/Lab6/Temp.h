#pragma once
#include "stdafx.h"
class Temp
{
public:
	Temp(int k = 0, int degree = 0);
	Temp(const Temp& object);
	~Temp();
	
    Temp& operator+=(const Temp& object);

	friend Temp operator+(const Temp& object1, const Temp& object2);
	friend std::istream& operator>>(std::istream& in, Temp& object);
	friend std::ostream& operator<<(std::ostream& out, const Temp& object);
private:
	int degree;
	int k;
};