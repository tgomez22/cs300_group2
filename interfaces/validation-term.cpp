#include "validation-term.h"

#include <string>
#include <iostream>
#include <cstring>

#include "util-term.h"
#include "simulator-term.h"
#include "provider-term.h"
#include "manager-term.h"
#include "cuecat.h"
#include "../datacenter.h"
#include "../model/entity.h"
#include "../data_structures/personList.h"
#include "../data_structures/serviceList.h"
#include "../model/person.h"
#include "../model/provider.h"
#include "../model/member.h"

using namespace std;

const int FAILED_ID_READ = 1;
const int ID_SIZE = 9;

void chooseTerm() {
   int numChoices = 4;
   string choices[numChoices] = {"Enter Provider Terminal", "Enter Manager Terminal", "Enter Simulator Terminal", "Quit"};
   int (* dt[numChoices])() = {idThenProvider, idThenManager, simulatorTerm, exitFunction};

   while(true) {  
     //This while loops allows us to automatically hop back up to this level when a lower level interface returns 
    //use a quit() option with the exitFunction() in
    //util-term.h to exit the program.
    //No 'exit value' here, because this is the top of the interface hierarchy
    menu("Choose from the following:", choices, dt, numChoices);
  }
}

int idThenProvider() {
    char tryAgain = '\0';

    while(true) {
      string id_num = getId();
      if(id_num == "") {
         break; 
      }
      if(datacenter::instance()->validateProvider(id_num)) {
        providerTerm(id_num);
        break; //Go back to terminal choice
      } else {
        cout << "Validation failed, would you like to try another ID number? (y/n)" << endl;
        cin >> tryAgain;
        cleanupCin();
        if(tryAgain  == 'y') {
          continue; //Try again!
        } else {
          break; //Go back to terminal choice
        }
      }  
    }
   return 0;
}

int idThenManager() {
    char tryAgain = '\0';

    while(true) {
      string id_num = getId();
      if(id_num == "") {
         break; 
      }
      if(datacenter::instance()->validateManager(id_num)) {
        managerTerm(id_num);
        break; //Go back to terminal choice
      } else {
        cout << "Validation failed, would you like to try another ID number? (y/n)" << endl;
        cin >> tryAgain;
        cleanupCin();
        if(tryAgain  == 'y') {
          continue; //Try again!
        } else {
          break; //Go back to terminal choice
        }
      }  
    }
   return 0;
}

//Returns a valid ID number or an empty string if user fails to enter ID
string getId() {
  int numChoices = 4;
  string choices[numChoices] = {"Scan ID number", "Type ID number", "Quit", "Quit Program"};
  int (* dt[numChoices])() = {scanId, typeId, returnExitValue, exitFunction};

  while(true) {  
     //This while loops allows us to automatically hop back up to this level when a lower level interface returns 
     int returnCode = menu("Choose from the following:", choices, dt, numChoices);

     //three options: 
     //User wants to go up a level (quit)
     if(returnCode == EXITVALUE) {
       return "";
     //User sucessfully entered an ID code
     } else if(returnCode != FAILED_ID_READ) { 
       return to_string(returnCode);
     }
     //User failed to enter an ID code and wants to try a different option (restart loop)
  }
}

int scanId()
{
   entity one_user;
   bool checkValue = false;
   int errorValue = 0;
   int keepGoing = 0;
   char answerYN = 'n';
   string id;

   do{
      cout << "Please scan the ID with your CueCat now.\n";
      id = getCueCat();
  
      if(!datacenter::instance()->checkIdFormat(id))
      {
	 errorValue = 0;
         cout << "Would you like to try again (y/n)?\n";
	 cin >> answerYN;
         cleanupCin();

	 answerYN = tolower(answerYN);
	 if(answerYN == 'y')
	 {
            keepGoing = 0;
	 }
	 else
         { 
            id = ""; //They don't want to set an id
            keepGoing = 1;
         }
      }
      else
      {
         errorValue = 1;
         keepGoing = 1;
	 cout << "Successfully got ID!" << endl;
         cout << "The ID Number is: ";
         cout << id << endl;
      }
   } while (keepGoing == 0);

   if(id.compare("") == 0) {
     return FAILED_ID_READ;
   } else {
     return stoi(id, NULL); //Hack :(
   }
}

int typeId() {
        string id;
	bool success = false;
        char response;

        do {
	  cout << "Please enter a User Identification number: ";
	  getline(cin, id);

          if(!datacenter::instance()->checkIdFormat(id)) {
            cout << "ID number format is invalid, try again? (y/n)" << endl;
            cin >> response;
            cleanupCin();
            if(response == 'y') {
              continue;
            } else {
              return FAILED_ID_READ;
            }
          } else {
            return stoi(id, NULL); //Hack :(
          }
        } while(true);
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
