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
	if (temp != nullptr)
		delete[] temp;
	this->temp = new Temp[size];
	for (int i=0; i < size; i++)
		temp[i] = object.temp[i];
	return *this;
}

Polynom operator+(const Polynom& object1, const Polynom& object2)
{
	Polynom a;
	a = object1;
	for (int i = 0; i < object2.size; i++)
	{
		bool isRegistered = false;
		for (int j = 0; j < a.size; j++)
		{
			if (object2.temp[i].getDegree() == a.temp[j].getDegree())
			{
				a.temp[j].operator+=(object2.temp[i]);
				isRegistered = true;
				break;
			}
		}
		if (!isRegistered)
		{
			Temp* copy = new Temp[a.size+1];
			for (int i = 0; i < a.size; i++)
			{
				copy[i] = a.temp[i];
			}
			copy[a.size] = object2.temp[i];
			a.temp = copy;
			copy = nullptr;
			a.size++;
		}
	}
	return a;
}

Polynom operator*(Polynom& object1, Polynom& object2)
{
	if (object1.size > object2.size)
	{
		Polynom temp;
		temp = object2;
		object2 = object1;
		object1 = temp;
	}

	Polynom* arr = new Polynom[object1.size];
	for (int i = 0; i < object1.size; i++)
	{
		arr[i] = object2;
		for (int j = 0; j < object2.size; j++)
		{
			arr[i].temp[j].setDegree(arr[i].temp[j].getDegree() + object1.temp[i].getDegree());
			arr[i].temp[j].setK(arr[i].temp[j].getK() * object1.temp[i].getK());
		}
	}
	Polynom res;
	res = arr[0];
	for (int i = 1; i < object1.size; i++)
	{
		res = res + arr[i];
	}
	delete[] arr;
	return res;
}

std::ostream& operator<<(std::ostream& out, const Polynom& object)
{
	for (int i = 0; i < object.size - 1; i++)
	{
		for (int j = i + 1; j < object.size; j++)
		{
			if (object.temp[i].getDegree() < object.temp[j].getDegree())
			{
				Temp copy = object.temp[i];
				object.temp[i] = object.temp[j];
				object.temp[j] = copy;
			}
		}
	}
	for (int i = 0; i < object.size; i++)
	{
		if (object.temp[i].getK() != 0)
		{
			out << object.temp[i];
			if (object.temp[i + 1].getK() > 0 && i + 1 != object.size)
				out << "+";
		}
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
			i--;
		}
	}

	if (object.temp != nullptr)
		delete[] object.temp;

	object.temp = new Temp;
	
	object.size = 1;

	for (int i = 0; str[i] != '\0';)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			Temp* copy = new Temp[object.size+1];
			for (int i = 0; i < object.size; i++)
				copy[i] = object.temp[i];
			object.temp = copy;
			object.size++;
		}
		bool isNegative = false;
		bool isDegree = false;
		bool isOne = true;
		int fullPart = 0;

		if (str[i] == '-')
		{
			isNegative = true;
			i++;
		}
		else
			if (str[i] == '+')
				i++;

		for (; str[i] != 'x'; i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				isOne = false;
				fullPart *= 10;
				fullPart += str[i] - '0';
			}
		}
		if (isOne)
			fullPart = 1;
		object.temp[object.size-1].setK(fullPart);

		for (; str[i] != '^'; i++);
		if (str[i] == '^')
			i++;
		for (; str[i]!='\0'; i++)
		{
			if (str[i] != '+' && str[i] != '-')
			{
				object.temp[object.size - 1].setDegree(object.temp[object.size - 1].getDegree() * 10);
				object.temp[object.size - 1].setDegree(object.temp[object.size - 1].getDegree() + (str[i] - '0'));
			}
			else break;
		}
		if (isNegative)
			object.temp[object.size - 1].setK(object.temp[object.size - 1].getK() * (-1));
	}
	object.sort();
	return in;
}

Polynom& Polynom::sort()
{
	int size = this->size;
	for (int i = 0; i < this->size-1; i++)
	{
		for (int j = i+1; j < this->size; j++)
		{
			if (this->temp[i].degree == this->temp[j].degree)
			{
				this->temp[i].k += this->temp[j].k;
				Temp* copy = new Temp[this->size - 1];
				for (int m = 0, n = 0; n < this->size; m++,n++)
				{
					if (m != j)
						copy[n] = this->temp[m];
					else
						n--;	
				}
				this->temp = copy;
				this->size--;
			}
		}
	}
	return *this;
}