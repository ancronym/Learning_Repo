// File_io_test_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>


int main()
{
	std::cout << "Here we go!" << std::endl;

	std::ofstream fout("../temponator.txt"); // initsialiseerime ofstream klassina fout, mis on seotud temp.txt-ga
	int val1, rel1;
	char val2[20],rel2[20];

	std::cout << "\n Enter the integer value: ";
	std::cin >> val1;
	std::cout << "\n Enter the string value: ";
	std::cin >> val2;

	fout << val1; fout << val2; /// Sisestame väärtused faili.

	fout.close(); /// Minetame fout objekti ja file temp.txt on nüüd vaba muuks kasutuseks.

	std::ifstream fin("../temponator.txt");	

	fin >> rel1;
	fin >> rel2;

	std::cout << "Integer value: " << rel1;
	std::cout << "String value: " << rel2;
	
	return 0;
}

