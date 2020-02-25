#include "person.h"
#include "entity.h"

person::person():entity()
{
}

person::~person()
{
}

person::person(const person & toAdd):entity(toAdd)
{
	name.add(toAdd.name);
	address.add(toAdd.address);
	city.add(toAdd.city);
	state.add(toAdd.state);
	zip.add(toAdd.zip);
}

void person::showInfo()const
{
    entity::display();
    name.display();
    address.display();
    city.display();
    state.display();
    zip.display();

    return;
}
