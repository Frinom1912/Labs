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
			spaceInd = i;
		else
			if (arr[i] == '/')
			{
				slashInd = i;
				break;
			}

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] != '-' && arr[i] != '/' && arr[i] != ' ' && (arr[i] < '0' || arr[i] > '9'))
		{
			std::cout << "Ввод неизвестных символов!\n";
			numinator = 0;
			denominator = 1;
			break;
		}
		else
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

Fraction::Fraction(double num, int N_DEC)
{
	this->toFraction(num, N_DEC);
}

Fraction::Fraction(const Fraction& object)
{
	*this = object;
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
	this->toFraction(num);
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

	this->operator+=(object);

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

Fraction& Fraction::operator-=(const Fraction& object)
{
	std::cout << "\n" << *this << " -= " << object << " = ";

	this->denominator *= object.denominator;
	this->numinator *= object.denominator;
	this->numinator -= object.numinator * this->denominator / object.denominator;
	
	this->sort();

	std::cout << *this << "\n";

	return *this;
}

Fraction& Fraction::operator-=(const double& object)
{
	std::cout << "\n" << *this << " -= " << object << " = ";

	Fraction temp(object);

	this->operator-=(temp);

	this->sort();

	std::cout << *this << "\n";

	return *this;
}

Fraction& Fraction::operator-=(const int& object)
{
	std::cout << "\n" << *this << " -= " << object << " = ";

	this->numinator -= object;

	std::cout << *this << "\n";

	return *this;
}


Fraction operator+(const Fraction& object1, const Fraction& object2)
{
	std::cout << "\n" << object1 << " + " << object2 << " = ";

	Fraction temp(object1);
	temp += object2;

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
	Fraction temp(object2);
	temp += object1;
	return temp;
}

Fraction operator-(const Fraction& object1, const Fraction& object2)
{
	Fraction temp(object1);
	temp -= object2;
	temp.sort();
	return temp;
}

Fraction operator-(Fraction& object1, const double& object2)
{
	Fraction temp(object1);
	temp -= object2;
	temp.sort();
	return temp;
}

Fraction operator-(Fraction& object1, const int& object2)
{
	Fraction temp(object1);
	temp -= object2;
	temp.sort();
	return temp;
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

		in.getline(arr, 15);

		object = arr;

		if (object.denominator != 0)
			break;
		else
			std::cout << "Ошибка, деление на 0!\n";
		/*
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
			std::cout << "\nОшибка, деление на ноль!\n";
			isNegative = false;
			full = 0;
		}
	}
	object.numinator += object.denominator * full;
	if (isNegative)
		object.numinator *= -1;
		*/
	}
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