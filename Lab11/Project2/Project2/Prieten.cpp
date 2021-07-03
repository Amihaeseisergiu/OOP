#include "Prieten.h"

#include <string>
#include <iostream>

using namespace std;

Prieten::Prieten()
{
	type = Friend;
	cout << "Adaugare Prieten:" << endl;
	cout << "Nume: ";
	cin >> nume;
	cout << endl <<"Data nasterii: ";
	cin >> data_nastere;
	cout << endl << "Telefon: ";
	cin >> telefon;
	cout << endl << "Adresa: ";
	cin >> adresa;
	cout << endl;
}

string Prieten::getName()
{
	return nume;
}

int Prieten::getType()
{
	return type;
}