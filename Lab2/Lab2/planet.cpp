#include "headers.h"

std::ofstream& Planet::operator<<(std::ofstream& out)
{
	if (Planet::ID == 0)
		out << std::left << std::setw(10) << "Название" << " " << std::setw(8) << "Диаметр" << " " << std::setw(7) << "Жизни" << " " << std::setw(9) << "Спутники\n";
	else
		out << std::left << std::setw(10) << this->name << " " << std::setw(8) << this->diameter << " " << std::setw(7) << this->satellite << " " << std::setw(9) << this->population << "\n";
	return out;
}

Planet::Planet()
{
	this->name = new char[1];
	this->name_size = 1;
	this->diameter = 0;
	this->satellite = 0;
	this->population = 0;
}

Planet& Planet::operator=(const Planet& object)
{
	this->name_size = object.name_size;
	this->name = new char[this->name_size];
	for (int i = 0; i < this->name_size; i++)
		this->name[i] = object.name[i];
	this->name[this->name_size] = '\0';
	this->diameter = object.diameter;
	this->population = object.population;
	this->satellite = object.satellite;
	return *this;
}

