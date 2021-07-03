#pragma once

#include "Fruct.h"

using namespace std;

class Portocala : public Fruct
{
public:
	Portocala();
	void accept(Visitor& vizitator);
};

