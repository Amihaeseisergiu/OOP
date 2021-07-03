#include "Portocala.h"

Portocala::Portocala()
{
	dimensiune = 3;
	culoare = "portocaliu";
}

void Portocala::accept(Visitor & vizitator)
{
	vizitator.visit(*this);
}
