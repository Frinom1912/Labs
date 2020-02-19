#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(const char*);
	Fraction(double, int );
	Fraction(int, int);
	//Fraction(const Fraction*);
	~Fraction();

	friend Fraction operator+(const Fraction& object1, const Fraction& object2);

private:
	int numinator;
	bool isNegative;
	int denominator;
};