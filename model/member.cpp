#include "member.h"

member::member():person()
{
}

member::member(const member & toAdd):person(toAdd)
{
	suspended = toAdd.suspended;
}

member::~member() {

}

void member::append()
{
//Mikayla do you want to do this interface?
}

std::list<service> member::getServiceList()
{
}
