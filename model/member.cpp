#include "member.h"
#include "entity.h"
#include "person.h"
#include <iostream>

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


      cout << "This member is not in our records.\n";
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

   tString name;
   tString address;
   tString city;
   tString state;
   tString zip;

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
        cout<<"Your account is suspended. "<<endl;
        cout<<"You owe: $"<<amtDue<<endl;
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
        display();
        return true;
    }

    else
        return false;
}
