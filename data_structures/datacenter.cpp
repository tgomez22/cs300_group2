
#include "datacenter.h"

datacenter::datacenter()
{
}


datacenter::~datacenter()
{
}

int datacenter::memberFunctions()
{
	//call functions for members of ChocAn
}

int datacenter::providerFunctions()
{
	//call functions for providers of ChocAn
}

int datacenter::managerFunctions()
{
	//call functions for managers of ChocAn
	return 0;
}

int datacenter::authenticateUser()
{
	//prompt a user to enter their member number, or tell me what args you need if you want to do it from main.
    //may have to pass in entity obj.
    int authorization = authenticateUser();

    //member
    if(authorization == 1)
        return memberFunctions();
    //provider
    else if(authorization == 2)
        return providerFunctions();
    //manager
    else if(authorization == 3)
        return managerFunctions();
    //not found
    else
        return 0;
}

int datacenter::addMember()
{
	//prompt user
}

int datacenter::addProvider()
{

}
