#include "entity.h"
#include <cstring>

//default constructor, no data members to initalize.
entity::entity()
{

}

//copy constructor, allows the id to be initalized to the 
//argument's data.
entity::entity(const entity & toAdd)
{
	id = toAdd.id;	
}

//default destructor, no data members to clear dynamic memory for, since
//data members manage it.
entity::~entity()
{

}

//prompts user to add an id number. Returns true if successfully added
//a valid length member id. returns false if can't add. 
bool entity::getIdFromTerm()
{
	char temp[ID];
	using namespace std;
	cout<<"Please enter a new User Identification number: ";
	cin.get(temp, ID, '\n');
	cin.ignore(100, '\n');

        
        strcpy(temp, isIDValid(temp));

	int length = strlen(temp);

	while(length < 9 || length > 9)
	{
		cout<<"IN GET ID FROM TERM.User Identification number must be 9 digits long."<<endl;
		cout<<"Please enter a new User Identification number: ";
		cin.get(temp, ID, '\n');
		cin.ignore(100, '\n');

		length = strlen(temp);
		
	}
	id = atoi(temp);
	return id;
}

//checks the scanned ID number to see if it is valid
bool entity::checkIdFromScan(char * scanID)
{
   int length = strlen(scanID);
   using namespace std;
   bool checkValue = false;

   if(length < 9 || length > 9)
   {
      cout << "Sorry. User ID must be 9 digits long." << endl;
      cout << "Please try again." << endl;
      checkValue = false;
   }
   else
   {
      checkValue = true; 
   }

   return checkValue;
}

//Checks if the ID is valid and makes sure the input is correct
char * entity::isIDValid(char * compare)
{
  int length = strlen(compare);
  using namespace std;
  
  if(length < 9 || length > 9)
  {
    cout<<"IN IS ID VALID.User Identification number must be 9 digits long."<<endl;
    cout<<"Please enter a new User Identification number: ";
    cin.get(compare, '\n');
    cin.ignore(100, '\n');

    length = strlen(compare);
    return isIDValid(compare);
  }
  return compare;
}

id_num entity::getIdValue()const
{
	return id;
}

		
int entity::compare(const entity & toCompare)const
{
	return id == toCompare.id;
}
