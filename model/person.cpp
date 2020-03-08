//This is the implementation file for the person object in person.h
//

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
    using namespace std;
	
    entity::display();
    cout << endl;
    cout << "Name: ";
    name.display();
    cout << endl;
    cout << "Street: ";
    address.display();
    cout << endl;
    cout << "City: ";
    city.display();
    cout << endl;
    cout << "State: ";
    state.display();
    cout << endl;
    cout << "Zip: ";
    zip.display();
    cout << endl;

    return;
}

void person::addInfo(char * addID, char * addName, char * addAddress, char * addCity, char * addState, char * addZip)
{
	entity::addId(addID);
	name.add(addName);
	address.add(addAddress);
	city.add(addCity);
	state.add(addState);
	zip.add(addZip);
	return;
}
