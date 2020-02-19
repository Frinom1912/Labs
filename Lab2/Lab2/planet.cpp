#include "headers.h"

Planet::Planet()
{
	this->name = new char[1];
	this->name_size = 1;
	this->diameter = 0;
	this->satellite = 0;
	this->population = false;
}

Planet::Planet(const Planet& object)
{
	*this = object;
}

Planet::~Planet()
{
	this->diameter = 0;
	this->population = false;
	this->satellite = 0;
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

void Planet::sortName(Planet* object, const int& objectCount)
{
	for (int i = 0; i < objectCount - 1; i++)
	{
		for (int j = i + 1; j < objectCount; j++)
		{
			if (object[i] < object[j])
			{
				Planet temp;
				temp = object[i];
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
	std::ofstream out("text.txt", std::ios_base::trunc);
	out << std::left << std::setw(15) << "��������" << " " << std::setw(10) << "�������" << " " << std::setw(8) << "�����" << " " << "��������\n";
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
			std::cout << "\n������� ����������� ��������, ��������� ����!\n";
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
			std::cout << "\t�������������� ������\n";
			for (int j = 0; j < objectCount; j++)
			{
				std::cout << j + 1 << ") " << object[j];
			}
			std::cout << "\n\n�������� ������ (����� �� 1 �� " << objectCount << "): ";
			int editStr;
			std::cin >> editStr;
			int edit;
			while (true)
			{
				system("cls");
				std::cout << "\t�������������� ������\n";
				std::cout << "1) �������� ���\n";
				std::cout << "2) �������� �������\n";
				std::cout << "3) �������� ���������� �����\n";
				std::cout << "4) �������� ���������� ���������\n\n";
				std::cout << "������� ����� ��������: ";
				std::cin >> edit;
				if (edit < 1 && edit > 4)
				{
					std::cout << "\n������� ����������� ��������, ��������� ����!\n";
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
				std::cout << "������� ����� ���: ";
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
					std::cout << "������� ����� �������: ";
					std::cin >> newData;
					newDiameter = toInt(newData);
					if (newDiameter != -1)
						break;
					else
					{
						std::cout << "������������ ����!\n";
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
					std::cout << "������� ����� ��������� �����: ";
					std::cin >> newData;
					int i = 0;
					for (; newData[i] != '\0'; i++);
					if (i > 1 || (newData[0] > '1' || newData[0] < '0'))
					{
						std::cout << "������������ ����!\n";
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
					std::cout << "������� ����� ���������� ���������: ";
					std::cin >> newData;
					newSatellite = toInt(newData);
					if (newSatellite != -1)
						break;
					else
					{
						std::cout << "������������ ����!\n";
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
			std::cout << "�� �����!\n";
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
			std::cout << "\t�������������� ������\n";
			for (int j = 0; j < objectCount; j++)
			{
				std::cout << j + 1 << ") " << object[j];
			}
			std::cout << "\n\n�������� ������ (����� �� 1 �� " << objectCount << "): ";
			int editStr;
			while (true)
			{
				std::cin >> editStr;
				if (editStr > objectCount || editStr < 1)
					std::cout << "������, ������ ������ �� ����������!\n";
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
			std::cout << "�� ��� �����!\n";
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
	for (int i = 0; arr[i] != '\0'; i++)
		length++;
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

Planet* Planet::resize(Planet* object, int& arr_size, const int& num_of_resize)
{
	Planet* temp = new Planet[arr_size + num_of_resize];
	for (int j = 0; j < (num_of_resize > 0 ? arr_size : arr_size-num_of_resize); j++)
	{
		temp[j] = object[j];
	}
	if (object != nullptr)
		delete[] object;
	arr_size+=num_of_resize;
	return temp;
}