#include <iostream>
#include <string>
#include <windows.h>
#include "roman.h"
#include <cctype>

void convertIntToRoman()
{
	std::cout << "Введіть число: ";
	int number = 0;
	if (!(std::cin >> number))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Це не схоже на число. Спробуйте ще раз.\n";
		return;
	}

	std::string result = intToRoman(number);
	if (result.empty())
	{
		std::cout << "Число поза діапазоном 1..3999.\n";
		return;
	}

	std::cout << number << " = " << result << "\n";
}

void convertRomanToInt()
{
	std::cout << "Введіть римський запис (наприклад, MCMXCIV): ";
	std::string text;
	std::cin >> text;

	for (size_t i = 0; i < text.size(); ++i)
	{
		text[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(text[i])));
	}

	std::cout << text << " = " << romanToInt(text) << "\n";
}

void printMenu()
{
	std::cout << "\n Конвертер римських чисел \n";
	std::cout << "1 - число -> римський запис (ціле число від 1 до 3999)\n";
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
		if (command == "1")
		{
			convertIntToRoman();
		}
		else if (command == "2")
		{
			convertRomanToInt();
		}
		else
		{
			std::cout << "Цей пункт ще не працює.\n";
		}
	}

	std::cout << "До побачення.\n";
	return 0;
}