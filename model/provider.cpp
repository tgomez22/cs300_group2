//This is the implementation file for the provider object, found in provider.h
//

#include "provider.h"
#include "person.h"
#include "entity.h"
#include <iostream>
provider::provider():person()
{
    consultNum = 0;
    weeklyFee = 0.0;
}

provider::~provider()
{
}

provider::provider(const provider & toAdd):person(toAdd)
{
	consultNum = toAdd.consultNum;
	weeklyFee = toAdd.weeklyFee;
}

//terminal function to prompt user
bool provider::readIn()
{

}

//Here's your prototype Shawn!
void provider::writeOut()
{

}


void provider::display()const
{
	using namespace std;
	showInfo();
	cout<<"There were: "<<consultNum<<" consults this week."<<endl;
	cout<<"The fee owed to the provider this week is: $"<<weeklyFee<<endl;

	return;
}

bool provider::isSuspended()const
{
    return false;
}

//getter functions
char* provider::getName()
{
  return name.getString();
}
char* provider::getAddress()
{
  return address.getString();
}
char* provider::getCity()
{
  return city.getString();
}
char* provider::getState()
{
  return state.getString();
}
char* provider::getZip()
{
  return zip.getString();
}
float provider::getFee()
{
  return weeklyFee;
}
