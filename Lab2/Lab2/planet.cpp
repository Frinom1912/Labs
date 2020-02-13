#include "headers.h"

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

