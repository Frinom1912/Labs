#pragma once
#include "stdafx.h"
class Temp
{
public:
	friend class Polynom;
	Temp(int k = 0, int degree = 0);
	Temp(const Temp& object);
	~Temp();
    Temp& operator+=(const Temp& object);

	int getK();
	int getDegree();

	friend Temp operator+(const Temp& object1, const Temp& object2);
	friend std::istream& operator>>(std::istream& in, Temp& object);
	friend std::ostream& operator<<(std::ostream& out, const Temp& object);
	friend std::ostream& operator<<(std::ostream& out, const Polynom& object);
private:
	int degree;
	int k;
};