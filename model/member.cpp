//This is the implementation file for the functions given in member.h

#include "member.h"
#include "entity.h"
#include "person.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

member::member():person()
{
	suspended = false;
    amtDue = 0;
}

member::member(const member & toAdd):person(toAdd)
{
	suspended = toAdd.suspended;
	amtDue = toAdd.amtDue;
}

member::~member()
{

}

//Here's your prototype Shawn for writing out.
void member::writeOut()
{
	ofstream myfile;
	myfile.open("data/member.txt", ios::app);
	//bool fileOpened = myfile.is_open();
	if(myfile)
	{
		char * fileMemId = memId.getString();
		char * fileName = name.getString();
		char * fileAddress = address.getString();
		char * fileCity = city.getString();
		char * fileState = state.getString();
		char * fileZip = zip.getString();
		json toWrite;
		toWrite["memId"] = fileMemId;
		toWrite["name"] = fileName;
		toWrite["address"] = fileAddress;
		toWrite["city"] = fileCity;
		toWrite["zip"] = fileZip;
		toWrite["suspended"] = suspended;
		toWrite["amtDue"] = amtDue;
		myfile << toWrite;
		myfile.close();
		system("openssl aes-256-cbc -salt -pbkdf2 -in data/member.txt -out data/memberEncrypted.dat -pass pass:password"); //encryption
		delete []fileMemId, delete []fileName, delete []fileAddress, delete []fileCity, delete []fileState, delete []fileZip;
	}
	else
		cout << "Unable to open file." << endl;
	return;
}

//prototype for terminal group.
bool member::readIn()
{
   using namespace std;

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

//fior terminal group. feel free to change.
void member::display()const
{
    using namespace std;
    if(suspended == true)
    {
        cout<<"The account is suspended. "<<endl;
        cout<<"Amount owed: $"<<amtDue<<endl;
    }

    else
    {
        showInfo();
    }

    return;
}

bool member::isSuspended()const
{
    using namespace std;

    if(suspended == true)
    {
        return true;
    }

    else
        return false;
}
bool member::isSuspendedAndPrint()const
{
    using namespace std;

    if(suspended == true)
    {
        display();
        return true;
    }

    else
        return false;
}

//getter functions
char* member::getName()
{
  return name.getString();
}
char* member::getAddress()
{
  return address.getString();
}
char* member::getCity()
{
  return city.getString();
}
char* member::getState()
{
  return state.getString();
}
char* member::getZip()
{
  return zip.getString();
}
float member::getFee()
{
  return amtDue;
}

bool member::suspendMember()
{
    suspended = true;
    return true;
}

void member::addInfo(const char * addID, const char * addName, const char * addAddress, const char * addCity, const char * addState, const char * addZip, bool addSuspended, float addAmtDue)
{
	person::addInfo(addID, addName, addAddress, addCity, addState, addZip);
	suspended = addSuspended;
	amtDue = addAmtDue;
	return;
}
