#pragma once

#include "Fruct.h"

using namespace std;

class Grapefruit : public Fruct
{
public:
	Grapefruit();
	void accept(Visitor& vizitator);
};

