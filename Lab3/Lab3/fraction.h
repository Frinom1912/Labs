#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

class Fraction
{
public:
	Fraction(const char* arr);
	Fraction(double num, int N_DEC = 4);
	Fraction(int numinator = 0, int denominator = 1);
	Fraction(const Fraction& object);
	
	friend std::istream& operator>>(std::istream& in, Fraction& object);
	
	friend std::ostream& operator<<(std::ostream& out, const Fraction& object);
	
	friend Fraction operator+(const Fraction& object1, const Fraction& object2);
	friend Fraction operator+(const Fraction& object1, const double& object2);
	friend Fraction operator+(const Fraction& object1, const int& object2);
	friend Fraction operator+(const double& object1, const Fraction& object2);
	friend Fraction operator+(const int& object1, const Fraction& object2);
	friend Fraction operator-(const Fraction& object1, const Fraction& object2);	
	friend Fraction operator-(const Fraction& object1, const double& object2);
	friend Fraction operator-(const Fraction& object1, const int& object2);
	friend Fraction operator-(const double& object1, const Fraction& object2);
	friend Fraction operator-(const int& object1, const Fraction& object2);
	
	friend Fraction& operator+=(double& a, const Fraction& object);
	friend Fraction& operator+=(int& a, const Fraction& object);
	friend Fraction& operator-=(double& a, const Fraction& object);
	friend Fraction& operator-=(int& a, const Fraction& object);
	
	Fraction& operator=(const Fraction& object);
	Fraction& operator=(const double& object);
	Fraction& operator=(const int& object);
	Fraction& operator+=(const Fraction& object);
	Fraction& operator+=(const double& object);
	Fraction& operator+=(const int& object);
	Fraction& operator-=(const Fraction& object);
	Fraction& operator-=(const double& object);
	Fraction& operator-=(const int& object);

private:
	Fraction toFraction(double num, int N_DEC = 4);
	int numinator;
	int denominator;
};

int sort(int N, int M);