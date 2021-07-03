#include <iostream>

#include "Agenda.h"

using namespace std;

int main()
{
	Agenda a;
	a.AddContact("pRiETEN");
	a.AddContact("coLeg");
	a.AddContact("cUnOscUt");
	vector<Contact*> b;
	b = a.FriendList();
	cout << boolalpha << a.SearchContactByName("Gigel") << " " << boolalpha << a.SearchContactByName("Ion") << endl;
	for (auto it : b)
		cout << it->getName()<<endl;
	a.DeleteContactByName("Gigel");
	a.DeleteContactByName("Ion");
	a.DeleteContactByName("Vasile");
	system("Pause");
	return 0;
}