#include "stdafx.h"
using namespace std;
int main()
{
	MySet a("abc");

	a.add_element("abc");
	a.add_element("abc");
	a.add_element("ABC");
	a.add_element("AcDS");
	a.delete_element("ABC");
	a.delete_element("a");

	MySet b(a);

	cout << b;

	MySet c("a");

	b += a;

	MySet res;

	cout << b;

	system("pause");
	return 0;
}