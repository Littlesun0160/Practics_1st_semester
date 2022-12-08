#include <iostream>
#include "hpp\Functions.hpp"
#include "hpp\Multiplication.hpp"

int main()
{
	setlocale(LC_ALL, "ru");
	std::string A, B;
	std::cout << "Введите число А" << "\n";
	std::cin >> A;
	std::cout << "Введите число В" << "\n";
	std::cin >> B;

	const int l = 1000;
	int massA[1000] = { 0 }, massB[1000] = { 0 };
	Massive(A, massA, l);
	Massive(B, massB, l); //запись каждого числа по цифрам в массив

	std::string result1="";
	Summ(massA, massB, result1, l);
	std::cout << "Сумма равна" << result1 << "\n";

	std::string result2 = "";
	Mul(A, B, result2);
	std::cout << "Произведение равно" << result2 << "\n";
}