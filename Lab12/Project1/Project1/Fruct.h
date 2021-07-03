#pragma once

#include <string>
#include "Visitor.h"

using namespace std;

class Fruct
{
public:
	string culoare;
	int dimensiune;
	virtual void accept(Visitor& vizitator) = 0;
};

