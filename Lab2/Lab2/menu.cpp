#include "headers.h"

int Menu()
{
	std::cout << "\t\t\tÃËÀÂÍÎÅ ÌÅÍŞ\n";
	std::cout << "1) ×òåíèå ÁÄ èç ôàéëà.\n";
	std::cout << "2) Çàïèñü äàííûõ â ÁÄ â ôàéë.\n";
	std::cout << "3) Ñîğòèğîâêà ÁÄ.\n";
	std::cout << "4) Ğåäàêòèğîâàíèå ÁÄ.\n";
	std::cout << "5) Âûâîä ÁÄ íà ıêğàí.\n";
	std::cout << "6) Âûõîä.\n\n";
	std::cout << "Ââåäèòå íîìåğ æåëàåìîé îïåğàöèè: ";

	int res; 
	std::cin >> res;
	std::cin.clear();
	std::cin.ignore(10, '\n');
	return res;
}