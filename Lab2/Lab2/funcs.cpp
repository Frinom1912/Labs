#include "headers.h"

Planet* ReadBase(const char* fileName, Planet* object, int& objectCount)
{
	std::ifstream in(fileName);
	unsigned char sym;
	unsigned char lastSym = ' ';
	in >> std::noskipws >> sym;
	while (sym != '\n')
		in >> std::noskipws >> sym;
	while (!in.eof())
	{
		objectCount++;
		Planet* temp = new Planet[objectCount];
		for (int j = 0; j < objectCount - 1; j++)
		{
			temp[j] = object[j];
		}
		in >> temp[objectCount - 1];
		if (object != nullptr)
			delete[] object;
		object = temp;
		temp = nullptr;
	}
	in.close();
	return object;
}

void WriteBase(const char* fileName, const Planet* object, const int& objectCount)
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

Planet* EditBase(Planet* object, int& objectCount)
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
		std::cin.clear();
		std::cin.ignore(10, '\n');
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
				std::cout << "3) �������� ���������� ���������\n";
				std::cout << "4) �������� ���������� �����\n\n";
				std::cout << "������� ����� ��������: ";
				std::cin >> edit;
				if (edit < 1 && edit > 4)
				{
					std::cout << "\n������� ����������� ��������, ��������� ����!\n";
					_getch();
				}
				else
					break;
				std::cin.clear();
				std::cin.ignore(10, '\n');
			}
			switch (edit)
			{
			case 1:
			{
				system("cls");
				std::cout << "������� ����� ���: ";
				char newName[15];
				std::cin >> newName;
				object[editStr - 1].editName(newName);
				break;
			}
			case 2:
			{
				system("cls");
				std::cout << "������� ����� �������: ";
				int newDiameter;
				std::cin >> newDiameter;
				object[editStr - 1].editDiameter(newDiameter);
				break;
			}
			case 3:
			{
				system("cls");
				std::cout << "������� ����� ��������� �����: ";
				int newPopulation;
				std::cin >> newPopulation;
				object[editStr - 1].editPopulation(newPopulation);
				break;
			}
			case 4:
			{
				system("cls");
				std::cout << "������� ����� ���������� ���������: ";
				int newSatellite;
				std::cin >> newSatellite;
				object[editStr - 1].editSatellite(newSatellite);
				break;
			}
			}
		}
		else
		{
			system("cls");
			std::cout << "�� ��� �����!\n";
			_getch();
		}
		break;
	}
	case 2:
	{
		system("cls");
		Planet* temp = new Planet[objectCount + 1];
		for (int j = 0; j < objectCount; j++)
			temp[j] = object[j];
		std::cin >> temp[objectCount];
		delete[] object;
		object = temp;
		temp = nullptr;
		objectCount++;
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