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
   using namespace std;

   cout << "Finish making provider::readIn pls";

   char correctYN = 'n';
   char temp_name[NAMESZ];
   char temp_address[NAMESZ];
   char temp_city[CITYSZ];
   char temp_state[STATESZ];
   char temp_zip[ZIPSZ];

   do{

      for(int i=0; i < NAMESZ; ++i)
      {
         temp_name[i] = '\0';
         temp_address[i] = '\0';
      }

      for(int i=0; i < CITYSZ; ++i)
      {
         temp_city[i] = '\0';
      }

      for(int i=0; i < STATESZ; ++i)
      {
         temp_state[i] = '\0';
      }

      for(int i=0; i < ZIPSZ; ++i)
      {
         temp_zip[i] = '\0';
      }


      cout << "Please add the member information.\n\n";
      cout << "Name (Ex. Jane Smith): \n";
      cin.get(temp_name, NAMESZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Address Street (Ex. 4432 NE 44th Way): \n";
      cin.get(temp_address, NAMESZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Address City (Ex. Portland): \n";
      cin.get(temp_city, CITYSZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Address State Abbreviation (Ex. OR): \n";
      cin.get(temp_state, STATESZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Address Zip Code (Ex. 97201): \n";
      cin.get(temp_zip, ZIPSZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "You provided the following. Is it correct Y/N?\n";
      cout << "Name: " << temp_name << endl;
      cout << "Street: " << temp_address << endl;
      cout << "City: " << temp_city << endl;
      cout << "State: " << temp_state << endl;
      cout << "Zip Code: " << temp_zip << endl;

      cin >> correctYN;
      cin.ignore(SIZE, '\n');

      correctYN = tolower(correctYN);

   } while (correctYN == 'n');

   //memId.add(tempMemId);
   name.add(temp_name);
   address.add(temp_address);
   city.add(temp_city);
   state.add(temp_state);
   zip.add(temp_zip);

   return true;
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
bool provider::isSuspendedAndPrint()const
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

void provider::addInfo(const char * addID, const char * addName, const char * addAddress, const char * addCity, const char * addState, const char * addZip, int addConsultNum, float addWeeklyFee)
{
    person::addInfo(addID, addName, addAddress, addCity, addState, addZip);
    consultNum = addConsultNum;
    weeklyFee = addWeeklyFee;
    return;
}
