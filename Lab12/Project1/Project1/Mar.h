#pragma once

#include "Fruct.h"

using namespace std;

class Mar : public Fruct
{
public:
	Mar();
	void accept(Visitor& vizitator);
};

