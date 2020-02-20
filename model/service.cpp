#include "service.h"
#include <iostream>

service::service()
{
//TODO
}

//copy constructor for the service class, initalizes the data members to the argument's data 
//members values.
service::service(const service & toAdd)
{
	dos = toAdd.dos;
	currTime = toAdd.currTime;
	memName.assign(toAdd.memName);
	servName.assign(toAdd.servName);
	serviceCode = toAdd.serviceCode;
}

//sets next pointer to null, no dynamic memory to deallocate.
service::~service()
{
//TODO
}

bool service::getServiceFromTerm()
{
//Mikayla do you want to add this interface to prompt user to make changes?
}
