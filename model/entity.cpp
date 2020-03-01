#include "entity.h"
#include "tString.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
//const int SIZE = 101;
//const int MULTBY = 97;
//default constructor, no data members to initalize.
entity::entity()
{

}

//copy constructor, allows the memId to be initalized to the
//argument's data.
entity::entity(const entity & toAdd)
{
	memId.add(toAdd.memId);
}

//default destructor, no data members to clear dynamic memory for, since
//data members manage it.
entity::~entity()
{

}

bool entity::addId(const entity & toAdd)
{
    memId.add(toAdd.memId);
    return true;
}

//Decrpyts the file where the entity data is stored, writes entity object data to a text file,
//and then encrypts the file. Returns true if the file is successfully opened.
bool entity::writeOut()
{
	system("openssl aes-256-cbc -d -salt -pbkdf2 -in data/encrypted.dat -out data/entity.txt -pass pass:password"); //decryption
	ofstream myfile;
	myfile.open("data/entity.txt", ios::app);
	if(myfile)
	{
		char * toUse = memId.getString();
		json toWrite;
		toWrite["memId"] = toUse;
		myfile << toWrite;
		myfile.close();
		system("openssl aes-256-cbc -salt -pbkdf2 -in data/entity.txt -out data/encrypted.dat -pass pass:password"); //encryption
		delete []toUse;
	  return true;
	}
	else
		cout << "Unable to open file." << endl;
	return false;
}

//prompts user to add an id number. Returns true if successfully added
//a valid length member id. returns false if can't add.

bool entity::addIdFromTerm()
{
	char temp[SIZE];
	bool success = false;
	using namespace std;

	for(int i=0; i < SIZE; ++i)
	{
           temp[i] = '\0';
	}

	cout<<"Please enter a new User Identification number: ";
	cin.get(temp, SIZE, '\n');
	cin.ignore(SIZE, '\n');

        strcpy(temp, isIDValid(temp));

	int length = strlen(temp);

	while(length != 9)
	{
		cout<<"User Identification number must be 9 digits long."<<endl;
		cout<<"Please enter a new User Identification number: ";
		cin.get(temp, ID, '\n');
		cin.ignore(100, '\n');

		length = strlen(temp);

	}
	success = memId.add(temp);
	return success;
}

bool entity::checkIdFromScan(char * scanID)
{
   int length = strlen(scanID);
   using namespace std;
   bool checkValue = false;

   if(length != 9)
   {
      cout << "Sorry. User ID must be 9 digits long." << endl;
      cout << "Please try again." << endl;
      checkValue = false;
   }
   else
   {
      memId.add(scanID);
      checkValue = true;
   }

   return checkValue;
}

//adds id, initalizes id value to the argument.
bool entity::addId(const tString & toAdd)
{
	memId.add(toAdd);
}

//adds id, initalizes id value to the argument.
bool entity::addId(char * toAdd)
{
	memId.add(toAdd);
}

//Checks if the ID is valid and makes sure the input is correct
char * entity::isIDValid(char * compare)
{
  int length = strlen(compare);
  using namespace std;

  if(length != 9)
  {
    cout<<"User Identification number must be 9 digits long."<<endl;
    cout<<"Please enter a new User Identification number: ";
    cin.get(compare, SIZE, '\n');
    cin.ignore(SIZE, '\n');

    length = strlen(compare);
    return isIDValid(compare);
  }
  return compare;
}


//displays stored private data(member number)
void entity::display()const
{
	cout << "ID Number: ";
	memId.display();
	return;
}

//checks if argument's data is the same as the calling object's data.
bool entity::isMatch(const entity & toSee)const
{
	return memId.compare(toSee.memId);
}


int entity::getIdValue()const
{
	return memId.getArrayValue();
}

void entity::getMemId(tString & toUse)const
{
	memId.copyToArg(toUse);
	return;
}

void entity::getMemId(entity & toUse)const
{
	memId.copyToArg(toUse.memId);
	return;
}

int entity::compare(const entity & toCompare)const
{
	return memId.compare(toCompare.memId);
}
int entity::compare(char * toCompare)const
{
	return memId.compare(toCompare);
}
int entity::compare(const tString & toCompare)const
{
	return memId.compare(toCompare);
}

int entity::getFirstIndex()const
{
    return memId.getFirstIndex();
}

