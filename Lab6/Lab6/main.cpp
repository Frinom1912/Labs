#include "stdafx.h"
using namespace std;
int main()
{
	Polynom a;
	Polynom b(Temp(3,5));

	cin >> a;
	a = a + b;
	cout << a;

	system("pause");
	return 0;
}