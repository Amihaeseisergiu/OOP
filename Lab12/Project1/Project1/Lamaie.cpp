#include "Lamaie.h"

Lamaie::Lamaie()
{
	dimensiune = 2;
	culoare = "galben";
}

void Lamaie::accept(Visitor & vizitator)
{
	vizitator.visit(*this);
}
