#include "headers.h"

int Menu()
{
	std::cout << "\t\t\t������� ����\n";
	std::cout << "1) ������ �� �� �����.\n";
	std::cout << "2) ������ ������ � �� � ����.\n";
	std::cout << "3) ���������� ��.\n";
	std::cout << "4) �������������� ��.\n";
	std::cout << "5) ����� �� �� �����.\n";
	std::cout << "6) �����.\n\n";
	std::cout << "������� ����� �������� ��������: ";

	int res; 
	std::cin >> res;
	std::cin.clear();
	std::cin.ignore(10, '\n');
	return res;
}