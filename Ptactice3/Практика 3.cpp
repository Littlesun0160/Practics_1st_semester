#include <iostream>
#include <fstream>
#include "Functions.hpp"

int main()
{
	setlocale(LC_ALL, "RUS");
	std::ifstream File;
	File.open("input.txt", std::ios::in);

	std::string Alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	int Count[33] = { 0 };
	const int size = 100;
	std::string str[size] = {};
	int k = 0;
	
	while (!File.eof())
	{
		std::getline(File, str[k]);
		k++;
	}
	std::string Words[10000] = {};

	int m = 0;
	for (int i = 0; i < size; i++)
	{
		std::string word;
		while ((str[i].find(' '))!=(-1))
		{
			int x = str[i].find(' ');
			word = str[i];
			word.erase(x);
			str[i].erase(0, x+1);
			FindLetters(word, Alphabet, Count);
			Words[m] = word;
			m++;
		}
		word = str[i];
		Words[m] = word;
		FindLetters(word, Alphabet, Count);
		Words[m+1] = "   ";
		m += 2;
	}
	MostOften(Alphabet, Count);
	WordsWithLetters(Words, Alphabet);
	for (int i = 0; i < 1000; i++)
	{
		if (Words[i] == "   ")
		{
			std::cout<<"\n";
		}
		else { std::cout << Words[i] << " "; }
	}
	Out(Words);
}