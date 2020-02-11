#include "headers.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int input = 0;
	const char* name = "info.txt";

	while (input != 6)
	{
		system("cls");

		Menu();

		int res;
		std::cin >> res;
		std::cin.clear();
		std::cin.ignore(10, '\n');

		switch (res)
		{
		case 1:

			break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		default: 
			std::cout << "\nВведена неизвестная команда! Повторный ввод.\n"; 
			_getch(); 
			break;
		}
	}

	system("pause");
	return 0;
}