#include "headers.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int objectCount = 0;
	const char* name = "info.txt";
	Planet* object = nullptr;

	while (true)
	{
		int res = -1;
		while (true)
		{
			system("cls");
			Menu();
			std::cin >> res;
			if (res < 1 && res > 4)
			{
				std::cout << "\nВведена неизвестная операция, повторите ввод!\n";
				_getch();
			}
			else
				break;
		}
		switch (res)
		{
		case 1:
		{
			object = Planet::ReadBase("text.txt", object, objectCount);
			break;
		}
		case 2:
		{		
			Planet::WriteBase("text.txt", object, objectCount);
			break;
		}
		case 3:
		{
			Planet::sortName(object, objectCount);
			break;
		}
		case 4:
		{
			object = Planet::EditBase(object, objectCount);
			break;
		}
		case 5: 
		{
			std::cout << "   " << std::left << std::setw(15) << "Название" << " " << std::setw(10) << "Диаметр" << " " << std::setw(8) << "Жизни" << " " << "Спутники\n";
			for (int j = 0; j < objectCount; j++)
			{
				std::cout << j+1 << ") " << object[j];
			}
			_getch();
			break;
		}
		case 6: 
			return 0;
		}
	}
	delete[] object;
	system("pause");
	return 0;
}