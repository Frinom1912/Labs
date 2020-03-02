#include "stdafx.h"
using namespace std;

int main()
{
	Temp a(3, 2);
	Temp b(3);
	Temp c(a);

	cout << a << endl;

	Temp d;

	cin >> d;

	cout << d << endl;

	system("pause");
	return 0;
}