#include "Mar.h"

Mar::Mar()
{
	dimensiune = 4;
	culoare = "rosu";
}

void Mar::accept(Visitor & vizitator)
{
	vizitator.visit(*this);
}
