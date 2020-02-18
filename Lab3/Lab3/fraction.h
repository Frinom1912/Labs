#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(char*);
	Fraction(double);
	Fraction(const Fraction*);
private:
	int numinator;
	int denominator;
};