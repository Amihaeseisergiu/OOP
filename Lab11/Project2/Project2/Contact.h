#ifndef Contact_h
#define Contact_h

#include "string"

using namespace std;

enum ContactType { Friend, Colleague, Acquaintance };

class Contact {

public:

	virtual string getName() = 0;
	virtual int getType() = 0;

protected:
	string nume;
	ContactType type;
};

#endif // Contact_h

