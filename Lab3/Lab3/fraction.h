#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(const char*);
	Fraction(double num, int N_DEC = 4)
	{
		numinator = 0;
		denominator = pow(10, N_DEC);
		if (num >= 1)
		{
			numinator += denominator * (int)num;
			num -= (int)num;
		}

		int res = 0;
		for (int i = 0; i < N_DEC; i++)
		{
			num *= 10;
			res *= 10;
			res += (int)num;
			num -= (int)num;
		}
		numinator += res;
		this->sort();
	}

	Fraction(int, int);
	Fraction(const Fraction&);
	~Fraction();

	friend std::istream& operator>>(std::istream& in, Fraction& object);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& object);
	friend Fraction operator+(const Fraction& object1, const Fraction& object2);
	friend Fraction operator-(const Fraction& object1, const Fraction& object2);
	Fraction& operator=(const Fraction& object1);
	Fraction& operator=(const double& object);
private:

	void sort();

	int numinator;
	int denominator;
};