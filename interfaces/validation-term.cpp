#include "validation-term.h"

#include <string>
#include <iostream>
#include <cstring>

#include "util-term.h"
#include "cuecat.h"
#include "../model/entity.h"
#include "../data_structures/personList.h"
#include "../data_structures/serviceList.h"
#include "../model/person.h"
#include "../model/provider.h"
#include "../model/member.h"

using namespace std;


int chooseTerm() {
   string choices[3] = {"Scan ID number", "Type ID number", "Quit"};
   int (* dt[3])() = {scanId, typeId, exitFunction};

   while(true) {  
     //This while loops allows us to automatically hop back up to this level when a lower level interface returns 
     int returnCode = menu("Choose from the following:", choices, dt, 3);
     if(returnCode == EXITVALUE)
     {
       return 0;
     }
   }

}

int scanId()
{
   entity one_user;
   bool checkValue = false;
   int errorValue = 0;
   int keepGoing = 0;
   char answerYN = 'n';

   do{
      cout << "Please scan the ID with your CueCat now.\n";
      checkValue = getCueCat(one_user);
      if(checkValue == false)
      {
	 errorValue = 0;
         cout << "Would you like to try again?\n";
	 cin >> answerYN;
	 cin.ignore(100, '\n');

	 answerYN = tolower(answerYN);
	 if(answerYN == 'y')
	 {
            keepGoing = 0;
	 }
	 else
         {
            keepGoing = 1;
         }
      }
      else
      {
         errorValue = 1;
         keepGoing = 1;
	 cout << "Success Adding ID!" << endl;
         cout << "The ID Number is: ";
         one_user.display();
         cout  << endl;
      }
   } while (keepGoing == 0);
   //change the return value before deployment!!!
  
    if(checkValue) {
      tString ts;
      one_user.getMemId(ts);
  
      userTypeRouter(string(ts.getString()));
   }

   return 0;
}

int typeId() {
	char temp[SIZE] = {};
	bool success = false;

	for(int i=0; i < SIZE; ++i)
	{
           temp[i] = '\0';
	}

	cout << "Please enter a User Identification number: ";
	cin.get(temp, SIZE, '\n');
	cin.ignore(SIZE, '\n');

	int length = strlen(temp);


	while(length != 9)
	{
		cout<<"User Identification number must be 9 digits long."<<endl;
		cout<<"Please enter a new User Identification number: ";
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');

		length = strlen(temp);
	}
	string *test = new string(temp);
	userTypeRouter(*test);
        free(test);
        return 0;
}

void userTypeRouter(string memberId) {
   entity one_user;
   member one_member;
   serviceList my_service_list;
   personList my_person_list;
   bool checkValue = false;
   int errorValue = 0;
   int isOnList = 3;
   bool didWriteWork = false;
   bool addToPersonListCheck = false;
   int memOrProvider = 0;
   bool readInSuccess = false;

  //if person is not in the list then add them
      //otherwise it is a duplicate or problem
      addToPersonListCheck = my_person_list.add(one_user);
      if(addToPersonListCheck)
      {
         isOnList = my_service_list.isSuspended(one_user);
         //if member is suspended
         if(isOnList == 1)
         {
            cout << "Please see manager for suspended account.\n";
	    errorValue = 0;
         }
         //if member is active
         else if(isOnList == 0)
         {
            cout << "Validated!\n";
            cout << "The ID Number is: ";
            one_user.display();
	    cout << "\nThe member information is:" << endl;
	    one_member.display();
            cout  << endl;
	    errorValue = 1;
         }
         //if member is not on list
         else if(isOnList == 2)
         {
            //is it a member or a provider or manager?
            memOrProvider = one_user.getFirstIndex();
	    //if it is a member, then add the member
	    //if it is NOT a member then do something else
	    if(memOrProvider == 1)
	    {
               one_member.addId(one_user);
	       readInSuccess = one_member.readIn();
	       if(readInSuccess == true)
               {
                  didWriteWork = one_user.writeOut();
                  if(didWriteWork == true)
	          {
                     cout << "Success adding ID.\n";
                    // cout << "The ID Number is: ";
                    // one_user.display();
		     cout << "\nThe member information is:" << endl;
		     one_member.display();
				 one_member.writeOut(); //testing purposes only, will be moved
                     cout  << endl;
                     errorValue = 1;
                  }
                  else
	          {
                     cout << "Error adding ID.\n";
	             cout << "Please see manager.\n";
	             errorValue = 0;
	          }
	      }
              else
	      {
                 cout << "Error reading in Member information!\n";
		 errorValue = 0;
	      }
            }
	    else if(memOrProvider == 2)
	    {
               //call the provider functions
	    }
	    else if(memOrProvider == 3)
	    {
               //call the manager functions
	    }
	    else
	    {
	       errorValue = 0;
	    }
	 }
         else
         {
            errorValue = 0;
         }
      }
      else
      {
      //there is a duplicate number in the list or there was a problem
      //   cout << "Some kind of duplicate error.\n";
//	 cout << "Fix before deployment!!!!\n";
//	 errorValue = 0;


         isOnList = my_service_list.isSuspended(one_user);
         //if member is suspended
         if(isOnList == 1)
         {
            cout << "Please see manager for suspended account.\n";
	    errorValue = 0;
         }
         //if member is active
         else if(isOnList == 0)
         {
            cout << "Validated!\n";
            cout << "The ID Number is: ";
            one_user.display();
            cout  << endl;
	    errorValue = 1;
         }
         //if member is not on list
         else if(isOnList == 2)
         {
            didWriteWork = one_user.writeOut();
            if(didWriteWork == true)
	    {
               cout << "Success adding ID.\n";
               cout << "The ID Number is: ";
               one_user.display();
               cout  << endl;
               errorValue = 1;
            }
            else
	    {
               cout << "Error adding ID.\n";
	       cout << "Please see manager.\n";
	       errorValue = 0;
	    }
         }
         else
         {
            errorValue = 0;
         }
      }

}
