#ifndef Cunoscut_h
#define Cunoscut_h

#include "Contact.h"
#include "string"

using namespace std;


class Cunoscut : public Contact {

public:

	string getName();
	int getType();
	Cunoscut();

private:
	string telefon;
};

#endif // Cunoscut_h

