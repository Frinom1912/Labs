#include "stdafx.h"
using namespace std;

int main()
{
	Polynom a;
	Polynom b(Temp(3,5));

	cin >> a;
	cout << "a = " << a << '\n' << "b = " << b << '\n';
	cout << "a = a + b = " << a << " + " << b << " = "; 
	a = a + b;
	cout << a << '\n';
	cout << "b = b + 5x^2 = ";
	b = b + Polynom(Temp(5, 2));
	cout << b << '\n';

	Polynom c;
	cout << "c = a*b = " << a << " * " << b << " = ";
	c = a * b;
	cout << c << '\n';

	system("pause");
	return 0;
}