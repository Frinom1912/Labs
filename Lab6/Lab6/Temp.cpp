#include "stdafx.h"

Temp::Temp(int k, int degree)
{
	this->k = k;
	this->degree = degree;
}

Temp::Temp(const Temp& object)
{
	k = object.k;
	degree = object.degree;
}

Temp& Temp::operator+=(const Temp& object)
{
	if(this->degree == object.degree)
		this->k += object.k;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Temp& object)
{
	if (object.k != 1 && object.k != -1 && object.degree != 0)
		out << object.k;
	else
		if (object.k == -1 && object.degree != 0)
			out << "-";
	if (object.degree == 0 && object.k != 0)
	{
		out << object.k;
		return out;
	}
	else
	{
		if (object.k != 0 && object.degree == 1)
		{
			out << "x";
			return out;
		}
		else
			out << "x^" << object.degree;
	}
	return out;
}

Temp operator+(const Temp& object1, const Temp& object2)
{
	Temp temp(object1);
	temp += object2;
	return temp;
}

std::istream& operator>>(std::istream& in, Temp& object)
{
	char* arr = new char[50];
	bool isNegative = false;
	bool isDegree = false;
	bool isOne = true;
	int fullPart = 0;
	std::cin.getline(arr, 50);
	for (int i = 0; arr[i] != 'x'; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			isOne = false;
			fullPart *= 10;
			fullPart += arr[i] - '0';
		}
	}
	if (isOne)
		fullPart = 1;
	object.k = fullPart;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ' ')
			continue;
		if (arr[i] == '-')
		{
			isNegative = !isNegative;
			continue;
		}
		if (arr[i] == 'x')
		{
			isDegree = true;
			while (arr[i] != '^')
				i++;
			continue;
		}
		else
		{
			if (arr[i] != 'x' && arr[i] != '^' && arr[i] != ' ')
			{
				if (isDegree)
				{
					object.degree *= 10;
					object.degree += arr[i] - '0';
				}
			}
		}
	}
	if (isNegative)
		object.k *= -1;
	return in;
}

int Temp::getK()
{
	return k;
}

int Temp::getDegree()
{
	return degree;
}

void Temp::setDegree(int degree)
{
	this->degree = degree;
}

void Temp::setK(int k)
{
	this->k = k;
}