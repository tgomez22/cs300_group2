#include "member.h"

member::member():person()
{
	suspended = amtDue = 0;
}

member::member(const member & toAdd):person(toAdd)
{
	suspended = toAdd.suspended;
	amtDue = toAdd.amtDue;
}

void member::append()
{
//Mikayla do you want to do this interface?
}
