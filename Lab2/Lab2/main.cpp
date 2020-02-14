#include "headers.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	const char* name = "info.txt";

	Planet* object = nullptr;

	while (true)
	{
		int res = -1;
		while (true)
		{
			system("cls");
			Menu();
			std::cin >> res;
			if (res < 1 && res > 4)
			{
				std::cout << "\n������� ����������� ��������, ��������� ����!\n";
				_getch();
			}
			else
				break;
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
		switch (res)
		{
		case 1:
		{
			std::ifstream in("text.txt");
			unsigned char sym;
			unsigned char lastSym = ' ';
			in >> std::noskipws >> sym;
			while (sym != '\n')
				in >> std::noskipws >> sym;
			while (!in.eof())
			{
				i++;
				Planet* temp = new Planet[i];
				for (int j = 0; j < i - 1; j++)
				{
					temp[j] = object[j];
				}
				in >> temp[i - 1];
				if (object != nullptr)
					delete[] object;
				object = temp;
				temp = nullptr;
			}
			in.close();
			break;
		}
		case 2:
		{		
			std::ofstream out("text.txt", std::ios_base::trunc);
			out << std::left << std::setw(15) << "��������" << " " << std::setw(10) << "�������" << " " << std::setw(8) << "�����" << " " << "��������\n";
			for (int j = 0; j < i; j++)
			{
				out << object[j];
				if (j != i - 1)
					out << '\n';
			}
			out.close();
			break;
		}
		case 3: break;
		case 4:
		{
			int resEdit=-1;
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
				if (i > 0)
				{
					system("cls");
					std::cout << "\t�������������� ������\n";
					for (int j = 0; j < i; j++)
					{
						std::cout << j + 1 << ") " << object[j];
					}
					std::cout << "\n\n�������� ������ (����� �� 1 �� " << i << "): ";
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
				Planet* temp = new Planet[i + 1];
				for (int j = 0; j < i; j++)
					temp[j] = object[j];
				std::cin >> temp[i];
				delete[] object;
				object = temp; 
				temp = nullptr;
				i++;
				break;
			}
			case 3:
			{
				if (i > 0)
				{
					system("cls");
					std::cout << "\t�������������� ������\n";
					for (int j = 0; j < i; j++)
					{
						std::cout << j + 1 << ") " << object[j];
					}
					std::cout << "\n\n�������� ������ (����� �� 1 �� " << i << "): ";
					int editStr;
					while (true)
					{
						std::cin >> editStr;
						if (editStr - 1 > i-1 || editStr < 1)
							std::cout << "������, ������ ������ �� ����������!\n";
						else
							break;
					}
					Planet* temp = new Planet[i - 1];
					int k = 0;
					bool flag = true;
					if (editStr == i)
					{
						flag = false;
						i--;
					}
					for (int j = 0; j < i; j++, k++)
					{
						if (j == editStr - 1 && j != i - 1)
						{
							j++;
						}
						temp[k] = object[j];
					}
					delete[] object;
					object = temp;
					temp = nullptr;
					if (flag)
						i--;
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

			break;
		}
		case 5: 
		{
			std::cout << "   " << std::left << std::setw(15) << "��������" << " " << std::setw(10) << "�������" << " " << std::setw(8) << "�����" << " " << "��������\n";
			for (int j = 0; j < i; j++)
			{
				std::cout << j+1 << ") " << object[j];
			}
			_getch();
			break;
		}
		case 6: 
			return 0;
		}
	}
	delete[] object;
	system("pause");
	return 0;
}