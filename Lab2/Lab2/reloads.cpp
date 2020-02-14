#include "headers.h"

std::ofstream& operator<<(std::ofstream& out, const Planet& object)
{
	out << std::left << std::setw(10) << object.name << " " << std::setw(8) << object.diameter << " " << std::setw(7) << object.population << " " << std::setw(9) << object.satellite;
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
			if (countSp == 0)
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
			}
			else
			{
				if (countSp == 1)
				{
					object.diameter *= 10;
					object.diameter += sym - '0';
				}
				else
				{
					if (countSp == 2)
					{
						object.population *= 10;
						object.population += sym - '0';
					}
					else
					{
						if (countSp == 3)
						{
							object.satellite *= 10;
							object.satellite += sym - '0';
						}
					}
				}
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
	out << std::left << std::setw(10) << object.name << " " << std::setw(8) << object.diameter << " " << std::setw(7) << object.population << " " << std::setw(9) << object.satellite << "\n";
	return out;
} 

std::istream& operator>>(std::istream& in, Planet& object)
{
	std::cout << "¬ведите название планеты: ";
	char newName[20];
	std::cin >> newName;
	int i = 0;
	for (; newName[i] != '\0'; i++);
	if (object.name != nullptr)
		delete[] object.name;
	object.name = new char[i + 1];
	for (int j = 0; j < i + 1; j++)
		object.name[j] = newName[j];
	object.name_size = i + 1;
	std::cout << "\n¬ведите диаметр планеты: ";
	int newDiameter;
	std::cin >> newDiameter;
	object.diameter = newDiameter;
	std::cout << "\n¬ведите состо€ние жизни на планете: ";
	int newPopulation;
	std::cin >> newPopulation;
	object.population = newPopulation;
	std::cout << "\n¬ведите количество спутников планеты: ";
	int newSatellite;
	std::cin >> newSatellite;
	object.satellite = newSatellite;
	return in;
}