#include "Grapefruit.h"

Grapefruit::Grapefruit()
{
	dimensiune = 4;
	culoare = "portocaliu";
}

void Grapefruit::accept(Visitor & vizitator)
{
	vizitator.visit(*this);
}
