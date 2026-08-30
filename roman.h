#pragma once
#include <string>

// Межі діапазону, який записується класичними римськими цифрами.
const int ROMAN_MIN = 1;
const int ROMAN_MAX = 3999;

// Перетворює ціле число в римський запис.
// Повертає порожній рядок, якщо число поза діапазоном ROMAN_MIN..ROMAN_MAX.
std::string intToRoman(int number);

// Перетворює римський запис у ціле число.
int romanToInt(const std::string& text);