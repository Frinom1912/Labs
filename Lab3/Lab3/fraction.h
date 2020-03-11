#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(const char*);
	Fraction(double num, int N_DEC = 4);
	Fraction(int, int denominator = 1);
	Fraction(const Fraction&);
	
	friend std::istream& operator>>(std::istream& in, Fraction& object);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& object);
	friend Fraction operator+(const Fraction& object1, const Fraction& object2);
	friend Fraction operator+(const Fraction& object1, const double& object2);
	friend Fraction operator+(const Fraction& object1, const double& object2);
	friend Fraction operator-(const Fraction& object1, const Fraction& object2);
	friend Fraction operator-(Fraction& object1, const double& object2);
	friend Fraction operator-(Fraction& object1, const int& object2);
	Fraction& operator=(const Fraction& object1);
	Fraction& operator=(const double& object);
	Fraction& operator=(const int& object);
	Fraction& operator+=(const Fraction& object);
	Fraction& operator+=(const double& num);
	Fraction& operator+=(const int& num);
	Fraction& operator-=(const Fraction& object);
	Fraction& operator-=(const double& num);
	Fraction& operator-=(const int& num);

private:

	void sort();
	Fraction toFraction(double& num, int N_DEC = 4);
	int numinator;
	int denominator;
};