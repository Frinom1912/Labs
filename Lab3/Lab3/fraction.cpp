#include "fraction.h"

Fraction::Fraction(const char* arr)
{
	int length = -1, full = 0;
	bool isFull = false, isOk = true;
	
	for (; arr[++length] != '\0';);

	char* temp = new char[++length];

	for (int i = 0; i < length-1; i++)
	{
		temp[i] = arr[i];
		if(arr[i] > '9' || arr[i] < '0')
			if (arr[i] != ' ' && arr[i] != '-' && arr[i] != '/')
			{
				isOk = false;
			}
	}
	temp[length-1] = '\0';
	int minusID = -1, slashID = -1, spaceID = -1;

	if (isOk)
	{
		for (int i = 0; temp[i] == ' ' && temp[i] != '\0'; i++)
		{
			for (int j = i--; temp[j] != '\0'; j++)
				temp[j] = temp[j + 1];
		}

		for (int i = 0; temp[i] != '\0'; i++)
		{
			switch (temp[i])
			{
			case '-':
			{
				minusID = i;
				break;
			}
			case '/':
			{
				slashID = i;
				break;
			}
			case ' ':
			{
				spaceID = i;
				break;
			}
			}
			if (temp[i + 1] == '\0' && slashID == -1)
			{
				slashID = i + 1;
				isFull = true;
			}
		}

		if (minusID > 0)
		{
			std::cout << "Неверный ввод строки\n";
			numinator = 0;
			denominator = 1;
		}
		else
		{
			numinator = 0;
			denominator = 0;
			for (int i = 0; temp[i] != '\0'; i++)
			{
				if (temp[i] == ' ' || temp[i] == '/' || temp[i] == '-')
					continue;
				if (i < spaceID)
				{
					full *= 10;
					full += temp[i] - '0';
				}
				else
					if (i > spaceID && i < slashID)
					{
						numinator *= 10;
						numinator += temp[i] - '0';
					}
					else
						if (i > slashID)
						{
							denominator *= 10;
							denominator += temp[i] - '0';
						}
			}
		}
		if (isFull)
			denominator = 1;
		else
			if (denominator == 0)
			{
				std::cout << "Неверный ввод строки: деление на 0\n";
				numinator = 0;
				denominator = 1;
				full = 0;
			}
		numinator += denominator * full;
		if (minusID == 0)
			numinator *= -1;
		int del = sort(numinator, denominator);
		numinator /= del;
		denominator /= del;
	}
	else
	{
		std::cout << "Неверный ввод строки: неизвестный символ\n";
		numinator = 0;
		denominator = 1;
	}
}

Fraction::Fraction(int num, int denom)
{
	numinator = num;
	denominator = denom;
	int del = sort(numinator, denominator); 
	numinator/=del; 
	denominator/=del;
}

Fraction::Fraction(double num, int N_DEC)
{
	toFraction(num, N_DEC);
}

Fraction::Fraction(const Fraction& object)
{
	*this = object;
}

Fraction& Fraction::operator=(const Fraction& object)
{
	numinator = object.numinator;
	denominator = object.denominator;
	return *this;
}

Fraction& Fraction::operator=(const double& object)
{
	double temp = object;
	toFraction(temp);
	int del = sort(numinator, denominator); 
	numinator/=del; 
	denominator/=del;
	return *this;
}

Fraction& Fraction::operator=(const int& object)
{
	numinator = object;
	denominator = 1;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& object)
{
	std::cout << "\n" << *this << " += " << object << " = ";

	numinator *= object.denominator;
	numinator += object.numinator * denominator;
	denominator *= object.denominator;
	int del = sort(numinator, denominator); 
	numinator/=del; 
	denominator/=del;

	std::cout << *this << '\n';

	return *this;

}

Fraction& Fraction::operator+=(const double& num)
{
	Fraction object(num);

	operator+=(object);

	return *this;
}

Fraction& Fraction::operator+=(const int& num)
{
	std::cout << "\n" << *this << " += " << num << " = ";

	numinator += num *denominator;
	int del = sort(numinator, denominator); 
	numinator/=del; 
	denominator/=del;

	std::cout << *this << "\n";

	return *this;
}

Fraction& Fraction::operator-=(const Fraction& object)
{
	std::cout << "\n" << *this << " -= " << object << " = ";

	numinator *= object.denominator;
	numinator -= object.numinator * denominator;
	denominator *= object.denominator;

	int del = sort(numinator, denominator);
	numinator/=del; 
	denominator/=del;

	std::cout << *this << "\n";

	return *this;
}

Fraction& Fraction::operator-=(const double& object)
{

	Fraction temp(object);

	operator-=(temp);

	return *this;
}

Fraction& Fraction::operator-=(const int& object)
{
	std::cout << "\n" << *this << " -= " << object << " = ";

	numinator -= object*denominator;

	std::cout << *this << "\n";

	return *this;
}

Fraction operator+(const Fraction& object1, const Fraction& object2)
{
	Fraction temp(object1);
	temp += object2;
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

Fraction operator+(const double& object1, const Fraction& object2)
{
	return operator+(object2,object1);
}

Fraction operator+(const int& object1, const Fraction& object2)
{
	return operator+(object2,object1);
}

Fraction operator-(const Fraction& object1, const Fraction& object2)
{
	Fraction temp(object1);
	temp -= object2;
	return temp;
}

Fraction operator-(const Fraction& object1, const double& object2)
{
	Fraction temp(object1);
	temp -= object2;
	return temp;
}

Fraction operator-(const Fraction& object1, const int& object2)
{
	Fraction temp(object1);
	temp -= object2;
	return temp;
}

Fraction operator-(const double& object1, const Fraction& object2)
{
	return operator-(object2, object1);
}

Fraction operator-(const int& object1, const Fraction& object2)
{
	return operator-(object2, object1);
}

std::istream& operator>>(std::istream& in, Fraction& object)
{
	char arr[25];
	
	in.getline(arr, 25);

	object = arr;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& object)
{
	if (abs(object.numinator) > abs(object.denominator) && object.denominator !=1)
	{
		out << object.numinator / object.denominator << " " << abs(object.numinator%object.denominator) << "/" << object.denominator;
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

int sort(int N, int M)
{
	if (abs(N % M) == 0 || abs(N) == 0)
		return abs(M);
	return sort(abs(M), abs(N % M));
}

Fraction Fraction::toFraction(double num, int N_DEC)
{
	numinator = 0;
	denominator = pow(10, N_DEC);
	int res = 0;
	if (num >= 1)
	{
		numinator += denominator * (int)num;
		num -= (int)num;
	}
	for (int i = 0; i < N_DEC; i++)
	{
		num *= 10;
		res *= 10;
		res += (int)num;
		num -= (int)num;
	}
	numinator += res;
	int del = sort(numinator, denominator); 
	numinator/=del; 
	denominator/=del;
	return *this;
}

Fraction& operator+=(double& a, const Fraction& object)
{
	std::cout << "\n" << a << " += " << object << " = ";
	Fraction temp(a);
	temp += object;
	std::cout << temp << '\n';
	return temp;
}

Fraction& operator+=(int& a, const Fraction& object)
{
	std::cout << "\n" << a << " += " << object << " = ";
	Fraction temp(a);
	temp += object;
	std::cout << temp << '\n';
	return temp;
}

Fraction& operator-=(double& a, const Fraction& object)
{
	std::cout << "\n" << a << " -= " << object << " = ";
	Fraction temp(a);
	temp -= object;
	std::cout << temp << '\n';
	return temp;
}

Fraction& operator-=(int& a, const Fraction& object)
{
	std::cout << "\n" << a << " -= " << object << " = ";
	Fraction temp(a);
	temp -= object;
	std::cout << temp << '\n';
	return temp;
}