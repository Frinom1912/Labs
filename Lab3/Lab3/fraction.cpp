#include "headers.h"

Fraction::Fraction()
{
	numinator = 0;
	denominator = 1;
	isNegative = false;
}

Fraction::Fraction(const char* arr)
{
	numinator = 0;
	isNegative = false;
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
}

Fraction::Fraction(double num, int N_DEC = 4)
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
}

Fraction::Fraction(int num, int denom)
{
	numinator = num;
	denominator = denom;
}

Fraction::~Fraction()
{	
	numinator = NULL;
	denominator = NULL;	
}

Fraction operator+(const Fraction& object1, const Fraction& object2)
{
	return Fraction(object1.numinator * object2.denominator + object2.numinator * object1.denominator, object1.denominator * object2.denominator);
}