#include "Agenda.h"
#include "Prieten.h"
#include "Coleg.h"
#include "Cunoscut.h"
#include <iostream>

using namespace std;

void Agenda::toLwr(string& update)
{
	for (size_t i = 0; i <= update.size(); ++i)
		if (update[i] >= 'A' && update[i] <= 'Z')
			update[i] = update[i] + 32;
}

void Agenda::AddContact(const string& type)
{
	string comp = type;
	toLwr(comp);
	if (comp == "prieten")
	{
		Contact* ct = new Prieten;
		contacts.push_back(ct);
	}
	else if (comp == "coleg")
	{
		Contact* ct = new Coleg;
		contacts.push_back(ct);
	}
	else if (comp == "cunoscut")
	{
		Contact* ct = new Cunoscut;
		contacts.push_back(ct);
	}
}

void Agenda::DeleteContactByName(const string& nume)
{
	for (auto it = contacts.begin(); it != contacts.end(); ++it)
		if ((*it)->getName() == nume)
		{
			delete(*it);
			contacts.erase(it);
			return;
		}
}

bool Agenda::SearchContactByName(const string& nume)
{
	for (auto c : contacts)
		if (c->getName() == nume)
			return true;

	return false;
}

vector<Contact*> Agenda::FriendList()
{
	vector<Contact*> ret;
	for (auto c : contacts)
		if (c->getType() == Friend)
			ret.push_back(c);
	return ret;
}

