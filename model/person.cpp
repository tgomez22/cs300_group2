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
void person::addInfo(userInfo & my_user)
{
   name.add(my_user.name);
   address.add(my_user.street);
   city.add(my_user.city);
   state.add(my_user.state);
   zip.add(my_user.zip);

   return;
}

void person::addInfo(person & my_person)
{
   name.add(my_person.name);
   address.add(my_person.address);
   city.add(my_person.city);
   state.add(my_person.state);
   zip.add(my_person.zip);

   return;
}

void person::addInfo(const char * addID, const char * addName, const char * addAddress, const char * addCity, const char * addState, const char * addZip)
{
	entity::addId(addID);
	name.add(addName);
	address.add(addAddress);
	city.add(addCity);
	state.add(addState);
	zip.add(addZip);
	return;
}
