#include "stdafx.h"

using namespace std;

int main()
{
	setlocale(0, "russian");
	
	MyVector<char*> v("Hello!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	cout << "Вектор v: " << v << endl;
	v.add_element("Привет!");
	v.add_element("Привет!");
	v.add_element("Привет!");
	cout << "Вектор v: " << v << endl;
	MyVector<char*> v1 = v;
	cout << "Вектор v1: " << v1 << endl;
	for (int i = 0; i < 5; i++)
		v1.delete_element(0);
	cout << "Вектор v1: " << v1 << endl;
	MySet<char*> s("Yes"), s1, s2;
	s.add_element("Привет!");
	s.add_element("No");
	char str[] = "Hello!";
	s.add_element(str);
	cout << "Множество s: " << s << endl;
	s1.add_element("Cat");
	s1.add_element("No");
	s1.add_element("Привет!");
	cout << "Множество s1: " << s1 << endl;
	s2 = (s1 - s);
	cout << "Множество s2=s1-s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = (s - s1);
	cout << "Множество s2=s-s1: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = (s1 + s);
	cout << "Множество s2=s1+s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	s2 = (s1 * s);
	cout << "Множество s2=s1*s: " << s2 << endl;
	cout << "Множество s1: " << s1 << endl;
	cout << "Множество s: " << s << endl;
	MySet<char*> s3 = s2;
	cout << "Множество s3=s2: " << s3 << endl;
	if (s3 == s2)
		cout << "Множество s3=s2\n";
	else
		cout << "Множество s3!=s2\n";
	if (s3 == s1)
		cout << "Множество s3=s1\n";
	else
		cout << "Множество s3!=s1\n";
	if (s1 == s3)
		cout << "Множество s1=s3\n";
	else
		cout << "Множество s1!=s3\n";

	// MySetTemp int
	cout << endl << endl;
	MySet<int> sT(1), s1T, s2T;
	sT.add_element(1);
	sT.add_element(2);
	int a = 13;
	sT.add_element(a);
	cout << "Множество s: " << sT << endl;
	s1T.add_element(6);
	s1T.add_element(2);
	s1T.add_element(1);
	cout << "Множество s1: " << s1T << endl;
	s2T = (s1T - sT);
	cout << "Множество s2=s1-s: " << s2T << endl;
	cout << "Множество s1: " << s1T << endl;
	cout << "Множество s: " << sT << endl;
	s2T = (sT - s1T);
	cout << "Множество s2=s-s1: " << s2T << endl;
	cout << "Множество s1: " << s1T << endl;
	cout << "Множество s: " << sT << endl;
	s2T = (s1T + sT);
	cout << "Множество s2=s1+s: " << s2T << endl;
	cout << "Множество s1: " << s1T << endl;
	cout << "Множество s: " << sT << endl;
	s2T = (s1T * sT);
	cout << "Множество s2=s1*s: " << s2T << endl;
	cout << "Множество s1: " << s1T << endl;
	cout << "Множество s: " << sT << endl;
	MySet<int> s3T = s2T;
	cout << "Множество s3=s2: " << s3T << endl;
	if (s3T == s2T)
		cout << "Множество s3=s2\n";
	else
		cout << "Множество s3!=s2\n";
	if (s3T == s1T)
		cout << "Множество s3=s1\n";
	else
		cout << "Множество s3!=s1\n";
	if (s1T == s3T)
		cout << "Множество s1=s3\n";
	else
		cout << "Множество s1!=s3\n";

	cout << endl << endl;
	MySet<double> sTe(1), s1Te, s2Te;
	sTe.add_element(1);
	sTe.add_element(2.5);
	double ae = 13.32;
	sTe.add_element(ae);
	cout << "Множество s: " << sTe << endl;
	s1Te.add_element(6.21);
	s1Te.add_element(2.5);
	s1Te.add_element(1);
	cout << "Множество s1: " << s1Te << endl;
	s2Te = (s1Te - sTe);
	cout << "Множество s2=s1-s: " << s2Te << endl;
	cout << "Множество s1: " << s1Te << endl;
	cout << "Множество s: " << sTe << endl;
	s2Te = (sTe - s1Te);
	cout << "Множество s2=s-s1: " << s2Te << endl;
	cout << "Множество s1: " << s1Te << endl;
	cout << "Множество s: " << sTe << endl;
	s2Te = (s1Te + sTe);
	cout << "Множество s2=s1+s: " << s2Te << endl;
	cout << "Множество s1: " << s1Te << endl;
	cout << "Множество s: " << sTe << endl;
	s2Te = (s1Te * sTe);
	cout << "Множество s2=s1*s: " << s2Te << endl;
	cout << "Множество s1: " << s1Te << endl;
	cout << "Множество s: " << sTe << endl;
	MySet<double> s3Te = s2Te;
	cout << "Множество s3=s2: " << s3Te << endl;
	if (s3Te == s2Te)
		cout << "Множество s3=s2\n";
	else
		cout << "Множество s3!=s2\n";
	if (s3Te == s1Te)
		cout << "Множество s3=s1\n";
	else
		cout << "Множество s3!=s1\n";
	if (s1Te == s3Te)
		cout << "Множество s1=s3\n";
	else
		cout << "Множество s1!=s3\n";

	system("pause");
	return 0;
}
