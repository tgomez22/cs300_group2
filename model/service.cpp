#include "service.h"
#include "tString.h"
#include <iostream>

service::service()
{
	next = NULL;
//Mikayla do you want to add the interface to prompt the user to enter their info?
}

//copy constructor for the service class, initalizes the data members to the argument's data 
//members values.
service::service(const service & toAdd)
{
	dos.add(toAdd.dos);
	currDate.add(toAdd.currDate);
	currTime.add(toAdd.currTime);
	servName.add(toAdd.ServName);
	memName.add(toAdd.memName);
	serviceCode.add(toAdd.serviceCode);
	serviceFee = toAdd.serviceFee;
	next = NULL;
}

//sets next pointer to null, no dynamic memory to deallocate.
service::~service()
{
	next = NULL;
}

//Displays stored information for a service.
void service::display()const
{
	using namespace std;

	cout<<"Service: "<<servName<<endl;
	cout<<"Service code: "<<servCode.display()<<endl;
	cout<<"Administered on: "<<dos.display()<<endl;
	cout<<"Filed on: "<<currDate.display()<<" at "<<currTime.display()<<endl;
	cout<<"Member: "<<memName.display()<<endl;
	cout<<"Member number: "<<entity::display()<<endl;
	cout<<"Fee for service provided: $"<<serviceFee<<endl;

	return;
}

bool service::appendService()
{
//Mikayla do you want to add this interface to prompt user to make changes?
}

//returns a pointer by reference to the next pointer.
service *& service::toNext()
{
	return next;
}
bool service::addService()
{
//Mikayla do you want to implement this interface?
}


