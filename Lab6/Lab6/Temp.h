#pragma once
#include "stdafx.h"
class Temp
{
public:
	Temp(int k = 0, int degree = 0);
	Temp(Temp& object);
	~Temp();
	friend std::istream& operator>>(std::istream& in, Temp& object);
	friend std::ostream& operator<<(std::ostream& out, const Temp& object);
private:
	int degree;
	int k;
};