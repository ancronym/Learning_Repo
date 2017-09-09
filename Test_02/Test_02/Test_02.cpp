// Test_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main() {
	ifstream infile;
	infile.open("E:/list.txt");

	// check for error
	if (!infile.fail()) {
		cerr << "File reading error!" << endl;
		exit(1);
	}
	string item;
	int count = 0;

	while (!infile.eof()) {
		infile >> item;
		cout << item << endl;
		count++;	
	}
	cout << count << " items in the list" << endl;

	return 0;
}