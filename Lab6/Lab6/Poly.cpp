#include "Poly.h"

Polynom::Polynom()
{
	temp = new Temp;
	temp->k = 0;
	temp->degree = 0;
	size = 1;
}

Polynom::Polynom(const Temp& object)
{
	temp = new Temp(object);
	size = 1;
}

Polynom::Polynom(const int num)
{
	temp = new Temp(num);
	size = 1;
}

Polynom Polynom::operator=(const Polynom& object)
{
	this->size = object.size;
	this->temp = new Temp[size];
	for (int i=0; i < size; i++)
		temp[i] = object.temp[i];
	return *this;
}

Polynom operator+(const Polynom& object1, const Polynom& object2)
{
	Polynom a(object1);
	bool isRegistered = false;
	for (int i = 0; i < object2.size; i++)
	{
		for (int j = 0; j < object1.size; j++)
		{
			if (object2.temp[i].getDegree() == object1.temp[j].getDegree())
			{
				a.temp[j].operator+=(object2.temp[i]);
				isRegistered = true;
				break;
			}
		}
		if (!isRegistered)
		{
			Temp* copy = new Temp[object1.size+1];
			for (int i = 0; i < object1.size; i++)
			{
				copy[i] = object1.temp[i];
			}
			copy[object1.size] = object2.temp[i];
			a.temp = copy;
			copy = nullptr;
			a.size++;
		}
	}
	return a;
}

std::ostream& operator<<(std::ostream& out, const Polynom& object)
{
	for (int i = 0; i < object.size; i++)
	{
		out << object.temp[i];
		if (object.temp[i+1].getK() > 0 && i+1!=object.size)
			out << "+";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Polynom& object)
{
	char str[50];

	in.getline(str,50);
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			for (int j = i; str[j] != '\0'; j++)
				str[j] = str[j + 1];
		}
	}

	if (object.temp != nullptr)
		delete[] object.temp;

	object.temp = new Temp;
	
	object.size = 1;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			Temp* copy = new Temp[object.size+1];
			for (int i = 0; i < object.size; i++)
				copy[i] = object.temp[i];
			object.temp = copy;
			object.size++;
			continue;
		}
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
	}
	return in;
}