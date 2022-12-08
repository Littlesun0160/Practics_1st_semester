#include "Functions.hpp"

#include <iostream>
#include <string>

void Massive(std::string x, int matrix[1000], const int len)
{
	int num;
	for (int i = 0; i < x.length(); i++)
	{
		num = (x[i]) - '0';
		matrix[len - x.length() + i] = num;
	}
}

void Summ(int mass1[1000], int mass2[1000], std::string& result, const int Len)
{
	int summa[1001] = { 0 };
	for (int i = Len-1; i >= 0; i--)
	{
		summa[i + 1] += mass1[i] + mass2[i];
		if (summa[i + 1] > 9)
		{
			summa[i] += 1;
			summa[i + 1] -= 10;
		}
	}

	for (int i = 0; i < Len+1; i++) //перевод из массива суммы в тип string
	{
		result += summa[i]+'0'; 
	}
	std::string num = "123456789";
	result.erase(0, result.find_first_of(num));
}