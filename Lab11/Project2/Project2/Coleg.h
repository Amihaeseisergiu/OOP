#ifndef Coleg_h
#define Coleg_h

#include "Contact.h"
#include "string"

using namespace std;

class Coleg : public Contact {

public:

	string getName();
	int getType();
	Coleg();

private:
	string telefon;
	string adresa;
	string firma;
};

#endif // Coleg_h

