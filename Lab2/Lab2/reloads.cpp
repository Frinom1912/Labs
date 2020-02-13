#include "headers.h"

std::ofstream& operator<<(std::ofstream& out, const Planet& object)
{
	if (Planet::ID == 0)
	{
		out << std::left << std::setw(10) << "��������" << " " << std::setw(8) << "�������" << " " << std::setw(7) << "�����" << " " << std::setw(9) << "��������\n";
		Planet::ID++;
	}
		out << std::left << std::setw(10) << object.name << " " << std::setw(8) << object.diameter << " " << std::setw(7) << object.satellite << " " << std::setw(9) << object.population << "\n";
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
					object.diameter += sym - '0';
					object.diameter *= 10;
				}
				else
				{
					if (countSp == 2)
					{
						object.population += sym - '0';
						object.population *= 10;
					}
					else
					{
						if (countSp == 3)
						{
							object.satellite += sym - '0';
							object.satellite *= 10;
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
		{
			in >> std::noskipws >> sym;
		}
		else
			flag = false;
	}

	object.diameter /= 10;
	object.population /= 10;
	object.satellite /= 10;

	return in;
}