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
	return Polynom(object);
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
		if (isRegistered)
		{
			Temp* copy = new Temp[object1.size+1];
			for (int i = 0; i < object1.size; i++)
			{
				copy[i] = object1.temp[i];
			}
			copy[object1.size] = object2.temp[i];
			a.temp = copy;
			copy = nullptr;
		}
	}

	return a;
}

std::ostream& operator<<(std::ostream& out, const Polynom& object)
{
	for (int i = 0; i < object.size; i++)
	{
		out << object.temp[i];
		if (object.temp[i].getK() > 0 && i+1!=object.size)
			out << " + ";
	}
	return out;
}
