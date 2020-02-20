#include "person.h"

person::person():entity()
{

}

person::~person() {

}

person::person(const person & toAdd):entity(toAdd)
{	
	name.assign(toAdd.name);
	address.assign(toAdd.address);
	city.assign(toAdd.city);
	state.assign(toAdd.state);
	zip.assign(toAdd.zip);
	//todo copy service list
}

