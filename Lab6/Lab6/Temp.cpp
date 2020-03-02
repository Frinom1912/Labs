#include "stdafx.h"

Temp::Temp(int k, int degree)
{
	this->k = k;
	this->degree = degree;
}

Temp::Temp(Temp& object)
{
	k = object.k;
	degree = object.degree;
}

Temp::~Temp()
{
	k = 0;
	degree = 0;
}

std::ostream& operator<<(std::ostream& out, const Temp& object)
{
	out << object.k << "x^" << object.degree;
}

std::istream& operator>>(std::istream& in, Temp& object)
{
	char arr[50];
	bool isDegree = false;
	in >> arr;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ' ')
			continue;
		else
		{
			if (isDegree)
			{
				object.degree *= 10;
				object.degree += arr[i] - '0';
			}
			else
			{
				object.k *= 10;
				object.k += arr[i] - '0';
			}
			if (arr[i] == 'x')
			{
				isDegree = true;
				continue;
			}
		}
	}
	return in;
}
