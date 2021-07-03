#pragma once

#include "Visitor.h"
#include <iostream>

using namespace std;

class VitaminaC : public Visitor
{
public:
	void visit(Grapefruit&);
	void visit(Portocala&);
	void visit(Lamaie&);
	void visit(Mar&);
};

