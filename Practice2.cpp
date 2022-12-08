#include <iostream>
#include "hpp\Functions.hpp"

int main()
{
	setlocale(LC_ALL, "ru");
	std::string A, B;
	std::cout << "Введите число А" << "\n";
	std::cin >> A;
	std::cout << "Введите число В" << "\n";
	std::cin >> B;

	int massA[1000] = { 0 }, massB[1000] = { 0 };
	Massive(A, massA);
	Massive(B, massB); //запись каждого числа по цифрам в массив

	std::string result1="";
	Summ(massA, massB, result1);
	std::cout << "Сумма равна " << result1 << "\n";

	Mul(A, B);
}