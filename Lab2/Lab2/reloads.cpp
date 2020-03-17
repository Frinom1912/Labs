#include "headers.h"

std::ofstream& operator<<(std::ofstream& out, const Planet& object)
{
	out << std::left << std::setw(15) << object.name << " " << std::setw(10) << object.diameter << " " << std::setw(6) << object.population << " " << object.satellite;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Planet& object)
{
	char sym;
	int countSp = 0;
	in >> std::noskipws >> sym;
	bool flag = false;
	while (sym != '\n' && !in.eof())
	{
		if (sym != ' ' && sym != '\t')
		{
			switch (countSp)
			{
			case 0:
			{
				char* temp = new char[object.name_size + 1];
				for (int i = 0; i < object.name_size; i++)
					temp[i] = object.name[i];
				temp[object.name_size - 1] = sym;
				temp[object.name_size] = '\0';
				object.name_size++;
				delete[] object.name;
				object.name = temp;
				temp = nullptr;
				break;
			}
			case 1:
				object.diameter *= 10;
				object.diameter += sym - '0';
				break;
			case 2:
				object.population = (sym != '0');
				break;
			case 3:
				object.satellite *= 10;
				object.satellite += sym - '0';
				break;
			}
		}
		else
		{
			while (sym == ' ' || sym == '\t')
				in >> std::noskipws >> sym;
			flag = true;
			countSp++;
		}
		if (!flag)
			in >> std::noskipws >> sym;
		else
			flag = false;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Planet& object)
{
	out << std::left << std::setw(15) << object.name << " " << std::setw(10) << object.diameter << " " << std::setw(6) << object.population << " " << object.satellite << "\n";
	return out;
} 

std::istream& operator>>(std::istream& in, Planet& object)
{
	std::cout << "Введите название планеты: ";
	char* newData = new char[15];
	std::cin >> newData;
	int i = 0;
	for (; newData[i] != '\0'; i++);
	if (object.name != nullptr)
		delete[] object.name;
	object.name = new char[i + 1];
	for (int j = 0; j < i + 1; j++)
		object.name[j] = newData[j];
	object.name_size = i + 1;
	delete[] newData;

	newData = new char[15];
	int newDiameter;
	while (true)
	{
		std::cout << "\nВведите диаметр планеты: ";
		std::cin >> newData;
		newDiameter = Planet::toInt(newData);
		if (newDiameter != -1)
			break;
		else
		{
			std::cout << "Некорректный ввод!\n";
			_getch();
		}
	}
	object.diameter = newDiameter;
	delete[] newData;

	newData = new char[15];
	bool newPopulation;
	while (true)
	{
		std::cout << "\nВведите состояние жизни: ";
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
	object.population = newPopulation;
	delete[] newData; 

	newData = new char[15];
	int newSatellite;
	while (true)
	{
		std::cout << "\nВведите количество спутников: ";
		std::cin >> newData;
		newSatellite = Planet::toInt(newData);
		if (newSatellite != -1)
			break;
		else
		{
			std::cout << "Некорректный ввод!\n";
			_getch();
		}
	}
	object.satellite = newSatellite;
	return in;
}

bool operator>(const Planet& object1, const Planet& object2)
{
	return (strcmp(object1.name, object2.name) > 0) ? true : false;
}