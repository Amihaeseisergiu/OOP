#include <iostream>

#include "Portocala.h"
#include "Mar.h"
#include "Lamaie.h"
#include "Grapefruit.h"
#include "VitaminaC.h"
#include <vector>

using namespace std;

int main()
{
	Portocala p; Mar m; Lamaie l; Grapefruit g;
	vector<Fruct* > fructe;
	fructe.push_back(&p);
	fructe.push_back(&m);
	fructe.push_back(&l);
	fructe.push_back(&g);
	VitaminaC v;
	for (Fruct* f : fructe)
		f->accept(v);
	system("Pause");
}