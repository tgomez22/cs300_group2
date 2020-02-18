
#include "dataCenter.h"

dataCenter::dataCenter() 
{
}

dataCenter::~dataCenter()
{
}

int dataCenter::memberFunctions()
{
	//call functions for members of ChocAn
}

int dataCenter::providerFunctions()
{
	//call functions for providers of ChocAn
}

int dataCenter::managerFunctions()
{
	//call functions for managers of ChocAn
}

int dataCenter::authenticateUser()
{
	//prompt a user to enter their member number, or tell me what args you need if you want to do it from main.
    //may have to pass in entity obj.
    int authorization = authentication.authenticateUser();
    
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

int dataCenter::addMember()
{
	//prompt user 
}

int dataCenter::addProvider()
{

}
