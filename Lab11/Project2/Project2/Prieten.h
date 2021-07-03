#ifndef Prieten_h
#define Prieten_h

#include "Contact.h"
#include "string"

using namespace std;

class Prieten : public Contact {

public:

	string getName();
	int getType();
	Prieten();

private:
	string data_nastere;
	string telefon;
	string adresa;
};

#endif // Prieten_h
