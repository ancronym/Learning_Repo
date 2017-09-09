// Cpp_short_and_sweet_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool again();

int main()
{
	string name;
	cout << "Mothertruckers!\n";
	cout << "Gimme your name, fool!\n";
	cin >> name;
	
	string greeting = " Hello, dumbass named " + name + "! ";
	string spaces(greeting.size(), ' ');
	string stars(greeting.size(), '*');
	
	cout << "*" << stars << "*" << endl
		<< "*" << spaces << "*" << endl
		<< "*"<< greeting<< "*"<< endl
		<< "*" << spaces << "*" << endl
		<< "*" << stars << "*" << endl << endl;

	float triangleA;
	float triangleB;
	
	do {
		cout << "Enter the two sides of the triangle: ";
		cin >> triangleA >> triangleB;


		float ratio = triangleB / triangleA;

		for (int i = 0; i <= (int)triangleA; i++)
		{
			float beam = i * ratio;
			string lineLength((int)beam, '*');
			cout << lineLength << endl;
		}
	} while (again());

    return 0;
}

bool again()
{
	string answer;
	cout << "again?";
	cin >> answer;
	if (answer[0] = 'y') { return true; }
	else { return false; }
}

