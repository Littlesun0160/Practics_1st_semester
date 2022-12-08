#include "Multiplication.hpp"

#include <iostream>
#include <string>

std::string Mul(std::string A, std::string B, std::string MulResult)
{
	using namespace std;
	if (B.length() > A.length())
	{
		string C = A;
		A = B; B = C;
	}
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