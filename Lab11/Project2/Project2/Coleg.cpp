#include "Coleg.h"
#include <iostream>

using namespace std;

Coleg::Coleg()
{
	type = Colleague;
	cout << "Adaugare Coleg:" << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << endl << "Telefon: ";
	cin >> telefon;
	cout << endl << "Adresa: ";
	cin >> adresa;
	cout << endl;
}

string Coleg::getName()
{
	return nume;
}

int Coleg::getType()
{
	return type;
}