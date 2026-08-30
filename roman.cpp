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

	int symbolValue(char c)
	{
		switch (c)
		{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default:  return 0;
		}
	}

	// Якщо цифра менша за наступну — вона віднімається (IV, IX, XL).
	int parseRoman(const std::string& text)
	{
		int total = 0;
		for (size_t i = 0; i < text.size(); ++i)
		{
			int current = symbolValue(text[i]);
			int next = 0;
			if (i + 1 < text.size())
			{
				next = symbolValue(text[i + 1]);
			}

			if (current < next)
			{
				total -= current;
			}
			else
			{
				total += current;
			}
		}
		return total;
	}
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

bool isValidRoman(const std::string& text)
{
	if (text.empty())
	{
		return false;
	}

	for (size_t i = 0; i < text.size(); ++i)
	{
		if (symbolValue(text[i]) == 0)
		{
			return false;
		}
	}

	// Запис коректний тоді, коли зворотне перетворення дає той самий рядок.
	return intToRoman(parseRoman(text)) == text;
}

int romanToInt(const std::string& text)
{
	if (!isValidRoman(text))
	{
		return 0;
	}
	return parseRoman(text);
}