#include <iostream>
#include <string>
#include <windows.h>

void printMenu()
{
	std::cout << "\n Конвертер римських чисел \n";
	std::cout << "1 - число -> римський запис\n";
	std::cout << "2 - римський запис -> число\n";
	std::cout << "0 - вихід\n";
	std::cout << "Ваш вибір: ";
}

int main()
{
	SetConsoleOutputCP(1251);

	std::string command;
	while (true)
	{
		printMenu();
		if (!(std::cin >> command))
		{
			break;
		}
		if (command == "0")
		{
			break;
		}
		std::cout << "Цей пункт ще не працює.\n";
	}

	std::cout << "До побачення.\n";
	return 0;
}