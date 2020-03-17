#include "headers.h"

Planet::Planet()
{
	name = new char;
	name_size = 1;
	diameter = 0;
	satellite = 0;
	population = false;
}

Planet::Planet(const Planet& object)
{
	*this = object;
}

Planet::~Planet()
{
	delete[] name;
}

Planet& Planet::operator=(const Planet& object)
{
	name_size = object.name_size;
	name = new char[name_size];
	for (int i = 0; i < name_size; i++)
		name[i] = object.name[i];
	diameter = object.diameter;
	population = object.population;
	satellite = object.satellite;
	return *this;
}

void Planet::editName(char* newName)
{
	if (name != nullptr)
		delete[] name;
	int i = length(newName) + 1;
	name = new char[i];
	for (int j = 0; j < i; j++)
		name[j] = newName[j];
	name_size = i;
}

void Planet::sortName(Planet* object, const int& objectCount)
{
	for (int i = 0; i < objectCount - 1; i++)
	{
		for (int j = i + 1; j < objectCount; j++)
		{
			if (object[i] > object[j])
			{
				Planet temp(object[i]);
				object[i] = object[j];
				object[j] = temp;
			}
		}
	}
}

Planet* Planet::ReadBase(const char* fileName, Planet* object, int& objectCount)
{
	std::ifstream in(fileName);
	unsigned char sym;
	in >> std::noskipws >> sym;
	while (sym != '\n')
		in >> std::noskipws >> sym;
	while (!in.eof())
	{
		object = resize(object, objectCount, 1);
		in >> object[objectCount-1];
	}
	in.close();
	return object;
}

void Planet::WriteBase(const char* fileName, const Planet* object, const int& objectCount)
{
	std::ofstream out(fileName, std::ios_base::trunc);
	out << std::left << std::setw(15) << "Название" << " " << std::setw(10) << "Диаметр" << " " << std::setw(8) << "Жизни" << " " << "Спутники\n";
	for (int j = 0; j < objectCount; j++)
	{
		out << object[j];
		if (j != objectCount - 1)
			out << '\n';
	}
	out.close();
}

Planet* Planet::EditBase(Planet* object, int& objectCount)
{
	int resEdit = -1;
	while (true)
	{
		system("cls");
		edit();
		std::cin >> resEdit;
		if (resEdit < 1 && resEdit > 4)
		{
			std::cout << "\nВведена неизвестная операция, повторите ввод!\n";
			_getch();
		}
		else
			break;
	}
	switch (resEdit)
	{
	case 1:
	{
		if (objectCount > 0)
		{
			system("cls");
			std::cout << "\tРЕДАКТИРОВАНИЕ СТРОКИ\n";
			for (int j = 0; j < objectCount; j++)
			{
				std::cout << j + 1 << ") " << object[j];
			}
			std::cout << "\n\nВыберите строку (число от 1 до " << objectCount << "): ";
			int editStr;
			std::cin >> editStr;
			int edit;
			while (true)
			{
				system("cls");
				std::cout << "\tРЕДАКТИРОВАНИЕ СТРОКИ\n";
				std::cout << "1) Изменить имя\n";
				std::cout << "2) Изменить диаметр\n";
				std::cout << "3) Изменить показатель жизни\n";
				std::cout << "4) Изменить количество спутников\n\n";
				std::cout << "Введите номер операции: ";
				std::cin >> edit;
				if (edit < 1 && edit > 4)
				{
					std::cout << "\nВведена неизвестная операция, повторите ввод!\n";
					_getch();
				}
				else
					break;
			}
			char newData[15]; 
			switch (edit)
			{
			case 1:
			{
				system("cls");
				std::cout << "Введите новое имя: ";
				std::cin >> newData;
				object[editStr - 1].editName(newData);
				break;
			}
			case 2:
			{
				system("cls");
				int newDiameter;
				while (true)
				{
					std::cout << "Введите новый диаметр: ";
					std::cin >> newData;
					newDiameter = toInt(newData);
					if (newDiameter != -1)
						break;
					else
					{
						std::cout << "Некорректный ввод!\n";
						_getch();
					}
				}
				object[editStr - 1].diameter = newDiameter;
				break;
			}
			case 3:
			{
				system("cls");
				bool newPopulation;
				while (true)
				{
					std::cout << "Введите новое состояние жизни: ";
					std::cin >> newData;
					int i = 0;
					for (; newData[i] != '\0'; i++);
					if (i > 1 || (newData[0] > '1' || newData[0] < '0'))
					{
						std::cout << "Некорректный ввод!\n";
						_getch();
					}
					else
						break;
				}
				newPopulation = newData[0] - '0';
					object[editStr - 1].population = newPopulation;
				break;
			}
			case 4:
			{
				system("cls");
				int newSatellite;
				while (true)
				{
					std::cout << "Введите новое количество спутников: ";
					std::cin >> newData;
					newSatellite = toInt(newData);
					if (newSatellite != -1)
						break;
					else
					{
						std::cout << "Некорректный ввод!\n";
						_getch();
					}
				}
				object[editStr - 1].satellite = newSatellite;
				break;
			}
			}
		}
		else
		{
			system("cls");
			std::cout << "БД пуста!\n";
			_getch();
		}
		break;
	}
	case 2:
	{
		system("cls");
		object = resize(object, objectCount, 1);
		std::cin >> object[objectCount-1];
		break;
	}
	case 3:
	{
		if (objectCount > 0)
		{
			system("cls");
			std::cout << "\tРЕДАКТИРОВАНИЕ СТРОКИ\n";
			for (int j = 0; j < objectCount; j++)
			{
				std::cout << j + 1 << ") " << object[j];
			}
			std::cout << "\n\nВыберите строку (число от 1 до " << objectCount << "): ";
			int editStr;
			while (true)
			{
				std::cin >> editStr;
				if (editStr > objectCount || editStr < 1)
					std::cout << "Ошибка, данная строка не существует!\n";
				else
					break;
			}
			Planet* temp = new Planet[objectCount - 1];
			int k = 0;
			bool flag = true;
			if (editStr == objectCount)
			{
				flag = false;
				objectCount--;
			}
			for (int j = 0; j < objectCount; j++, k++)
			{
				if (j == editStr - 1 && j != objectCount - 1)
				{
					j++;
				}
				temp[k] = object[j];
			}
			delete[] object;
			object = temp;
			temp = nullptr;
			if (flag)
				objectCount--;
		}
		else
		{
			system("cls");
			std::cout << "БД уже пуста!\n";
			_getch();
		}
		break;
	}
	case 4:	break;
	}
	return object;
}

int Planet::length(char* arr)
{
	int length = 0;
	for (; arr[length] != '\0'; length++);
	return length;
}

int Planet::toInt(const char* arr)
{
	int res = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			res *= 10;
			res += arr[i] - '0';
		}
		else
			return -1;
	}
	return res;
}

Planet* Planet::resize(Planet* object, int& size, const int& resize)
{
	Planet* temp = new Planet[size + resize];
	for (int j = 0; j < (resize > 0 ? size : size-resize); j++)
	{
		temp[j] = object[j];
	}
	if (object != nullptr)
		delete[] object;
	size+=resize;
	return temp;
}