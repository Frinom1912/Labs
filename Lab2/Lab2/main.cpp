#include "headers.h"

int Planet::ID = 0;
int main()
{
	setlocale(LC_ALL, "Rus");
	int input = 0;
	int i = 0;
	const char* name = "info.txt";

	Planet* object = new Planet[1];

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
				in >> object[i];
				i++;
				Planet* temp = new Planet[i+1];
				for (int j = 0; j < i; j++)
				{
					temp[j] = object[j];
				}
				if(object!=nullptr)
					delete[] object;
				object = temp;
				temp = nullptr;
			}
			break;
		}
		case 2:
		{		
			std::ofstream out("text.txt", std::ios_base::trunc);
			for (int j = 0; j < i-1; j++)
			{
				out << object[j];
			}
			break;
		}
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
	delete[] object;
	system("pause");
	return 0;
}