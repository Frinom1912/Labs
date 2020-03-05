#include "stdafx.h"
using namespace std;
int main()
{

	Temp a(3,2);
	Temp c(3, 4);
	Polynom b(a);
	Polynom d;
	d = b + c;

	system("pause");
	return 0;
}