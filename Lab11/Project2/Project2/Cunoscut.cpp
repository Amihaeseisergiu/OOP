#include "Cunoscut.h"
#include <iostream>
using namespace std;

Cunoscut::Cunoscut()
{
	type = Acquaintance;
	cout << "Adaugare Cunoscut:" << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << endl << "Telefon: ";
	cin >> telefon;
	cout << endl;
}

string Cunoscut::getName()
{
	return nume;
}

int Cunoscut::getType()
{
	return type;
}