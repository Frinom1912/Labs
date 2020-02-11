#include "headers.h"

std::ofstream& Planet::operator<<(std::ofstream& out)
{
	if (Planet::ID == 0)
		out << std::left << std::setw(10) << "Название" << " " << std::setw(8) << "Диаметр" << " " << std::setw(7) << "Жизни" << " " << std::setw(9) << "Спутники\n";
	else
		out << std::left << std::setw(10) << this->name << " " << std::setw(8) << this->diameter << " " << std::setw(7) << this->satellite << " " << std::setw(9) << this->population << "\n";
	return out;
}

Planet& Planet::operator>>(std::ifstream& in)
{
	char sym, lastsym = '1';
	int countSp = 0;
	in >> std::noskipws >> sym;

	while (sym != '\n' || !in.eof())
	{
		if (sym != ' ')
		{
			if (countSp == 0)
			{
				char* temp = new char[this->name_size + 1];
				for (int i = 0; i < name_size - 1; i++)
					temp[i] = this->name[i];
				temp[name_size - 1] = sym;
				temp[name_size] = '\n';
				name_size++;
				delete[] name;
				name = temp;
				temp = nullptr;
			}
			else
			{
				if (countSp == 1)
				{
					this->diameter += sym - '0';
					this->diameter *= 10;
				}
				else
				{
					if (countSp == 2)
					{
						this->population += sym - '0';
						this->population *= 10;
					}
					else
					{
						if (countSp == 3)
						{
							this->satellite += sym - '0';
							this->satellite *= 10;
						}
					}
				}
			}
		}
		else
		{
			if(lastsym != sym && sym == ' ')
				countSp++;
		}
		lastsym = sym;
	}

	return *this;
}

Planet::Planet()
{
	this->name = new char[2];
	this->name[0] = ' ';
	this->name[1] = '\n';
	this->name_size = 2;
	this->diameter = 0;
	this->satellite = 0;
	this->population = 0;
}

Planet::~Planet()
{
	delete[] this->name;
}