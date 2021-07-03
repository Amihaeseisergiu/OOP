#ifndef Agenda_h
#define Agenda_h

#include "Contact.h"
#include <vector>
#include <string>
using namespace std;

class Agenda {

public:

	void AddContact(const string& type);

	void DeleteContactByName(const string& nume);

	bool SearchContactByName(const string& nume);

	vector<Contact*> FriendList();

private:
	void toLwr(string& update);
	vector< Contact* > contacts;
};

#endif // Agenda_h

