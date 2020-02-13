#include "headers.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int input = 0;
	int i = 0;
	const char* name = "info.txt";

	Planet* object = nullptr;

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
		{
			std::ifstream in("text.txt");
			unsigned char sym;
			in >> std::noskipws >> sym;
			while (sym != '\n')
				in >> std::noskipws >> sym;
			while (!in.eof())
			{
				i++;
				Planet* temp = new Planet[i];
				for (int j = 0; j < i-1; j++)
				{
					temp[j] = object[j];
				}
				in >> temp[i-1];
				if(object!=nullptr)
					delete[] object;
				object = temp;
				temp = nullptr;
			}
			in.close();
			break;
		}
		case 2:
		{		
			std::ofstream out("text.txt", std::ios_base::trunc);
			out << std::left << std::setw(10) << "Название" << " " << std::setw(8) << "Диаметр" << " " << std::setw(7) << "Жизни" << " " << std::setw(9) << "Спутники\n";
			for (int j = 0; j < i-1; j++)
			{
				out << object[j];
			}
			out.close();
			break;
		}
		case 3: break;
		case 4: break;
		case 5: 
		{
			std::cout << std::left << std::setw(10) << "Название" << " " << std::setw(8) << "Диаметр" << " " << std::setw(7) << "Жизни" << " " << std::setw(9) << "Спутники\n";
			for (int j = 0; j < i; j++)
			{
				std::cout << object[j];
			}
			_getch();
			break;
		}
		case 6: 
			return 0;
		default: 
			std::cout << "\nВведена неизвестная команда! Повторный ввод.\n"; 
			_getch(); 
			break;
		}
	}
	delete[] object;
	system("pause");
	return 0;
}