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

Temp::~Temp()
{
	k = 0;
	degree = 0;
}

Temp& Temp::operator+=(const Temp& object)
{
	this->degree += object.degree;
	this->k += object.k;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Temp& object)
{
	out << object.k;
	if (object.degree == 0 && object.k != 0)
		return out;
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
	bool isDegree = false;
	std::cin.getline(arr, 50);
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ' ')
			continue;
		if (arr[i] == 'x')
		{
			isDegree = true;
			while (arr[i] != '^')
				i++;
			continue;
		}
		else
		{
			if(arr[i]!='x' && arr[i]!='^' && arr[i]!=' ')
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
		}
	}
	return in;
}
