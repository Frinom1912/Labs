#include "headers.h"

Planet::Planet()
{
	this->name = new char[1];
	this->name_size = 1;
	this->diameter = 0;
	this->satellite = 0;
	this->population = 0;
}

Planet::Planet(const Planet& object)
{
	*this = object;
}

Planet::~Planet()
{
	delete[] this->name;
}

Planet& Planet::operator=(const Planet& object)
{
	this->name_size = object.name_size;
	this->name = new char[this->name_size];
	for (int i = 0; i < this->name_size; i++)
		this->name[i] = object.name[i];
	this->diameter = object.diameter;
	this->population = object.population;
	this->satellite = object.satellite;
	return *this;
}

void Planet::editName(char* newName)
{
	if (this->name != nullptr)
		delete[] this->name;
	int i = 0;
	while (newName[i] != '\0')
		i++;
	this->name = new char[i+1];
	for (int j = 0; j < i + 1; j++)
		this->name[j] = newName[j];
	this->name_size = i+1;
}

void Planet::editDiameter(int& newDiameter)
{
	this->diameter = newDiameter;
}

void Planet::editSatellite(int& newSatellte)
{
	this->satellite = newSatellte;
}

void Planet::editPopulation(int& newPopulation)
{
	this->population = newPopulation;
}
