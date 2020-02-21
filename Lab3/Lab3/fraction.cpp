#include "headers.h"

Fraction::Fraction()
{
	numinator = 0;
	denominator = 1;
}

Fraction::Fraction(const char* arr)
{
	numinator = 0;
	bool isNegative = false;
	denominator = 0;
	int slashInd;
	int spaceInd = -1;
	int full = 0;
	for (int i = 0; arr[i] != '\0'; i++)
		if (arr[i] == ' ')
		{
			spaceInd = i;
		}
		else
		{
			if (arr[i] == '/')
			{
				slashInd = i;
				break;
			}
		}
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ' ')
			continue;
		if (arr[i] == '-')
		{
			isNegative = !isNegative;
		}
		else
		{
			if (i < spaceInd && spaceInd > 0)
			{
				full *= 10;
				full += arr[i] - '0';
			}
			else
			{
				if (arr[i] != '/' && slashInd > i)
				{
					numinator *= 10;
					numinator += arr[i] - '0';
				}
				else
				{
					if (arr[i] == '/')
						continue;
					else
					{
						denominator *= 10;
						denominator += arr[i] - '0';
					}
				}
			}
		}
	}
	numinator += denominator * full;
	if (isNegative)
		numinator *= -1;
	this->sort();
}

Fraction::Fraction(int num, int denom)
{
	numinator = num;
	denominator = denom;
	this->sort();
}

Fraction::Fraction(const Fraction& object)
{
	*this = object;
}

Fraction::~Fraction()
{	
	numinator = NULL;
	denominator = NULL;	
}

Fraction& Fraction::operator=(const Fraction& object1)
{
	this->numinator = object1.numinator;
	this->denominator = object1.denominator;
	return *this;
}

Fraction& Fraction::operator=(const double& object)
{
	double num = object;
	this->toFraction(num, 4);
	this->sort();
	return *this;
}

Fraction& Fraction::operator=(const int& object)
{
	this->numinator = object;
	this->denominator = 1;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& object)
{
	std::cout << "\n" << *this << " += " << object << " = ";

	this->denominator *= object.denominator;
	this->numinator *= object.denominator;
	this->numinator += object.numinator * this->denominator/object.denominator;
	this->sort();

	std::cout << *this << '\n';

	return *this;

}

Fraction& Fraction::operator+=(const double& num)
{
	Fraction object(num);
	std::cout << "\n" << *this << " += " << object << " = ";

	this->denominator *= object.denominator;
	this->numinator *= object.denominator;
	this->numinator += object.numinator * this->denominator / object.denominator;
	this->sort();

	std::cout << *this << "\n";

	return *this;
}

Fraction& Fraction::operator+=(const int& num)
{
	std::cout << "\n" << *this << " += " << num << " = ";

	this->numinator += num * this->denominator;
	this->sort();

	std::cout << *this << "\n";

	return *this;
}

Fraction operator+(const Fraction& object1, const Fraction& object2)
{
	std::cout << "\n" << object1 << " += " << object2 << " = ";
	Fraction temp(object1.numinator * object2.denominator + object2.numinator * object1.denominator, object1.denominator * object2.denominator);
	temp.sort();

	std::cout << temp << "\n";

	return temp;
}

Fraction operator+(const Fraction& object1, const double& object2)
{
	Fraction temp(object2);
	temp += object1;
	return temp;
}

Fraction operator+(const Fraction& object1, const int& object2)
{
	Fraction temp(object2,1);
	temp += object1;
	return temp;
}

Fraction operator-(const Fraction& object1, const Fraction& object2)
{
	Fraction temp(object1.numinator * object2.denominator - object2.numinator * object1.denominator, object1.denominator * object2.denominator);
	temp.sort();
	return temp;
}

Fraction operator-(Fraction& object1, const double& object2)
{
	Fraction temp(object2);
	object1 = object1 - temp;
	object1.sort();
	return object1;
}

Fraction operator-(Fraction& object1, const int& object2)
{
	Fraction temp(object2);
	object1 = object1 - temp;
	object1.sort();
	return object1;
}

std::istream& operator>>(std::istream& in, Fraction& object)
{
	object.denominator = 0;
	int slashInd;
	int spaceInd = -1;
	int full = 0;
	bool isNegative = false;
	while (object.denominator == 0)
	{
		char arr[15];

		for (int i = 0; arr[i - 1] != '\n'; i++)
			in >> std::noskipws >> arr[i];

		object.numinator = 0;
		for (int i = 0; arr[i] != '\n'; i++)
			if (arr[i] == ' ')
			{
				spaceInd = i;
			}
			else
			{
				if (arr[i] == '/')
				{
					slashInd = i;
					break;
				}
			}
		for (int i = 0; arr[i] != '\n'; i++)
		{
			if (arr[i] == ' ')
				continue;
			if (arr[i] == '-')
			{
				isNegative = !isNegative;
			}
			else
			{
				if (i < spaceInd && spaceInd > 0)
				{
					full *= 10;
					full += arr[i] - '0';
				}
				else
				{
					if (arr[i] != '/' && slashInd > i)
					{
						object.numinator *= 10;
						object.numinator += arr[i] - '0';
					}
					else
					{
						if (arr[i] == '/')
							continue;
						else
						{
							object.denominator *= 10;
							object.denominator += arr[i] - '0';
						}
					}
				}
			}
		}
		if (object.denominator == 0)
		{
			std::cout << "\n������, ������� �� ����!\n";
			isNegative = false;
			full = 0;
		}
	}
	object.numinator += object.denominator * full;
	if (isNegative)
		object.numinator *= -1;

	object.sort();

	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& object)
{
	if (std::abs(object.numinator) > std::abs(object.denominator) && object.denominator !=1)
	{
		out << object.numinator / object.denominator << " " << std::abs(object.numinator%object.denominator) << "/" << object.denominator;
	}
	else
	{
		if (object.denominator == 1)
			out << object.numinator;
		else
			out << object.numinator << "/" << object.denominator;
	}
	return out;
}

void Fraction::sort()
{
	int min = std::abs(numinator) < std::abs(denominator) ? std::abs(numinator) : std::abs(denominator);
	int del = 2;
	while (del <= min)
	{
		while (numinator % del == 0 && denominator % del == 0)
		{
			denominator /= del;
			numinator /= del;
		}
		del += 1;
	}
}

Fraction Fraction::toFraction(double& num, int N_DEC)
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
	return *this;
}