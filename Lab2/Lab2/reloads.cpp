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