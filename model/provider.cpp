//This is the implementation file for the provider object, found in provider.h
//

#include "provider.h"
#include "person.h"
#include "entity.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

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
	ofstream myFile;
	myFile.open("data/provider.txt", ios::app);
	if(myFile)
	{
		char * writeMemId = memId.getString();
		char * writeName = name.getString();
		char * writeAddress = address.getString();
		char * writeCity = city.getString();
		char * writeState = state.getString();
		char * writeZip = zip.getString();
		json toWrite;
		toWrite["memId"] = writeMemId;
		toWrite["name"] = writeName;
		toWrite["address"] = writeAddress;
		toWrite["city"] = writeCity;
		toWrite["zip"] = writeZip;
		toWrite["consultNum"] = consultNum;
		toWrite["weeklyFee"] = weeklyFee;
		myFile << toWrite;
		myFile.close();
		system("openssl aes-256-cbc -salt -pbkdf2 -in data/provider.txt -out data/providerEncrypted.dat -pass pass:password"); //encryption
		delete []writeMemId, delete []writeName, delete []writeAddress, delete []writeCity, delete []writeState, delete []writeZip;
	}
	else
		cout << "Unable to open file." << endl;
	return;
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

//always returns false. Easier to do this
//as the implementation of a virtual function
//then to dynamic cast to check object type.
bool provider::suspendMember()
{
    return false;
}

void provider::addInfo(const char * addID, const char * addName, const char * addAddress, const char * addCity, const char * addState, const char * addZip, int addConsultNum, flo    at addWeeklyFee)
{
    person::addInfo(addID, addName, addAddress, addCity, addState, addZip);
    consultNum = addConsultNum;
    weeklyFee = addWeeklyFee;
    return;
}
