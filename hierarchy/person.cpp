#include "person.h"

person::person():entity()
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
