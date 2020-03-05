#include <iostream>
#include "MyStack.h"
int main()
{
	MyStack<int> a;
	MyStack<int> b;

	int N;

	std::cin >> N;
	
	int original = N;
	int del = 2;

	while (N != 1)
	{
		while (N % del == 0)
		{
			a.push(del);
			N /= del;
		}
		if (del >= 3)
			del += 2;
		else
			del++;
	}


	std::cout << original << " = ";
	for (; !a.empty();)
	{
		std::cout << a.top_inf();
		b.push(a.top_inf());
		a.pop();
		if (!a.empty())
			std::cout << " * ";
	}
	std::cout << "\n";
	std::cout << original << " = ";
	for (; !b.empty();)
	{
		std::cout << b.top_inf();
		b.pop();
		if (!b.empty())
			std::cout << " * ";
	}
	std::cout << '\n';

	system("pause");
	return 0;
}