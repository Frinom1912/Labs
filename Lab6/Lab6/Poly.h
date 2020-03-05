#pragma once
#include "stdafx.h"

class Polynom
{
public:
	Polynom();
	Polynom(const Temp& object);
	Polynom(const int num);
	Polynom operator=(const Polynom& object);
	friend Polynom operator+(const Polynom& object1, const Polynom& object2);
	friend std::ostream& operator<<(std::ostream&, const Polynom& object);
private:
	Temp* temp;
	int size;
};