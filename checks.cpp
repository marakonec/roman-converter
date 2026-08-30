#include "checks.h"
#include "roman.h"

#include <iostream>
#include <string>

namespace
{
	int total = 0;
	int failed = 0;

	void report(const std::string& name, const std::string& got, const std::string& want)
	{
		++total;
		if (got == want)
		{
			std::cout << "  ok      " << name << "\n";
		}
		else
		{
			++failed;
			std::cout << "  ПОМИЛКА " << name
				<< ": отримано \"" << got
				<< "\", очікували \"" << want << "\"\n";
		}
	}

	std::string yesNo(bool value)
	{
		return value ? "так" : "ні";
	}
}

void runChecks()
{
	total = 0;
	failed = 0;

	std::cout << "\nКонтрольні приклади:\n";

	report("1 -> I", intToRoman(1), "I");
	report("1994 -> MCMXCIV", intToRoman(1994), "MCMXCIV");
	report("3999 -> MMMCMXCIX", intToRoman(3999), "MMMCMXCIX");
	report("0 поза діапазоном", intToRoman(0), "");
	report("4000 поза діапазоном", intToRoman(4000), "");
	report("MCMXCIV -> 1994", std::to_string(romanToInt("MCMXCIV")), "1994");
	report("IIII не є коректним", yesNo(isValidRoman("IIII")), "ні");
	report("порожній рядок не є коректним", yesNo(isValidRoman("")), "ні");

	std::cout << "Разом прикладів: " << total << ", не пройшли: " << failed << "\n";
}