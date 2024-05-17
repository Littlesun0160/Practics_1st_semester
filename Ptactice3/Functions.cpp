#include "Functions.hpp"
#include <iostream>
#include <string>
#include <fstream>

void FindLetters(std::string word, std::string Alphabet, int Count[])
{
	char str[101] = {};
	int k = 0;
	for (int i = 0; i < word.length(); i++)
	{
		char c = tolower(word[i]);
		if (!ispunct(c))
		{
			str[k] = c;
			k++;
		}
	}
	str[k] = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		Count[Alphabet.find_first_of(str[i])] += 1;
	}
}

void MostOften(std::string& Alphabet, int Count[])
{
	for (int i = 0; i < Alphabet.length() - 1; i++)
	{
		for (int j = i + 1; j < Alphabet.length(); j++)
		{
			if (Count[i] < Count[j])
			{
				std::swap(Count[i], Count[j]);
				std::swap(Alphabet[i], Alphabet[j]);
			}
		}
	}
	Alphabet.erase(4);
}

void WordsWithLetters(std::string Words[1000], std::string Let)
{
	for (int i = 0; i < 1000; i++)
	{
		std::string Word;
		Word = Words[i];
		bool IsPun = false;
		char Pun;
		if (Word != "" and ispunct(Word[Word.length() - 1]))
		{
			Pun = Word[Word.length() - 1];
			Word.erase(Word.length() - 1);
			IsPun = true;
		}
		for (int j = 0; j < Let.length(); j++)
		{
			for (int m = 0; m < Let.length(); m++)
			{
				if (j != m)
				{
					std::string L = "", Res="";
					L += Let[j]; Res += Let[j] - 32;
					L += Let[m]; Res += Let[m] - 32;
					std::string M = L;
					M.replace(0, 1, 1, M[0] - 32);

					if ((Word.find(L)!=(-1)) or ((Word.find(M))!= (-1)))
					{
						Word.insert(Word.length(), 1, '(');
						Word.insert(Word.length(), Res);
						Word.insert(Word.length(), 1, ')');
					}
				}
			}
		}
		if (IsPun)
		{
			Word += Pun;
		}
		Words[i] = Word;
	}
}

void Out(std::string Words[1000])
{
	std::ofstream result;
	result.open("output.txt");
	for (int i = 0; i < 1000; i++)
	{
		if (Words[i] == "   ")
		{
			result << "\n";
		}
		else { result << Words[i] << " "; }
	}
}
