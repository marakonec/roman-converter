#include "roman.h"

namespace
{
	struct RomanPair
	{
		int value;
		const char* symbol;
	};

	// Пари йдуть від найбільшої до найменшої, разом із відніманнями CM, CD, XC, XL, IX, IV.
	const RomanPair TABLE[] = {
		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
		{ 100, "C"}, { 90, "XC"}, { 50, "L"}, { 40, "XL"},
		{  10, "X"}, {  9, "IX"}, {  5, "V"}, {  4, "IV"},
		{   1, "I"}
	};

	const int TABLE_SIZE = 13;
}

std::string intToRoman(int number)
{
	if (number < ROMAN_MIN || number > ROMAN_MAX)
	{
		return "";
	}

	std::string result;
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		while (number >= TABLE[i].value)
		{
			result += TABLE[i].symbol;
			number -= TABLE[i].value;
		}
	}
	return result;
}