#include "../hpp/Functions.hpp"

#include <iostream>
#include <string>

void Massive(std::string x, int matrix[1000])
{
	int num;
	for (int i = 0; i < x.length(); i++)
	{
		num = (x[i]) - '0';
		matrix[1000 - x.length() + i] = num;
	}
}

void Summ(int mass1[1000], int mass2[1000], std::string& result)
{
	int summa[1001] = { 0 };
	for (int i = 999; i >= 0; i--)
	{
		summa[i + 1] += mass1[i] + mass2[i];
		if (summa[i + 1] > 9)
		{
			summa[i] += 1;
			summa[i + 1] -= 10;
		}
	}

	for (int i = 0; i < 1001; i++) //перевод из массива суммы в тип string
	{
		result += summa[i]+'0'; 
	}
	std::string num = "123456789";
	result.erase(0, result.find_first_of(num));
}

std::string Mul(std::string A, std::string B)
{
	std::string MulResult = "";
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	int Res[1000000] = { 0 };
	for (int i = 0; i < A.length(); i++)
	{
		for (int j = 0; j < B.length(); j++)
		{
			int a = A[i] - '0';
			int b = B[j] - '0';
			Res[i + j] += a * b;
			Res[i + j + 1] += Res[i] / 10;
			Res[i + j] = Res[i] % 10;
		}
	}
	for (int i = 0; i < A.length() + B.length(); i++) //перевод из массива суммы в тип string
	{
		MulResult += Res[i] + '0';
	}
	reverse(MulResult.begin(), MulResult.end());
	return MulResult;
}