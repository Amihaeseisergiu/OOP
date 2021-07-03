#pragma once

#include "Fruct.h"

using namespace std;

class Lamaie : public Fruct
{
public:
	Lamaie();
	void accept(Visitor& vizitator);
};

