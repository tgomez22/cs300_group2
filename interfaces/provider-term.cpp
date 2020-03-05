#include "provider-term.h"

#include <iostream>
#include <string>

#include "../datacenter.h"
#include "util-term.h"
#include "validation-term.h"

using namespace std;

int providerTerm(string id_num)
{
   int numChoices = 5;
   string choices[numChoices] = {"Create Service Record", "Run Reports", "Use Directory", "Quit", "Exit Program"};

   int (* dt[numChoices])(string) = {createServiceRecord, runProviderReport, useDirectory,
	                               returnExitValue2, exitFunction2};

   while(true)
   {
      int returnCode = menu2("Please choose from the following menu.", choices, dt, numChoices);
      if(returnCode == EXITVALUE)
      {
         return 0;
      }
   }

   return 0;
}

int createServiceRecord(string providerId)
{
   char tryAgain = '\0';

   while(true)
   {
      string id_num = getId();
      if(id_num == "")
      {
         break;
      }
      if(datacenter::instance()->validateMember(id_num))
      {
         fillServiceRecord(id_num, providerId);
	 break;  //Go back to terminal choice
      }
      else
      {
         cout << "Validation failed, would you like to try another ID number? (y/n)" << endl;
	 cin >> tryAgain;
	 cleanupCin();
	 if(tryAgain == 'y')
         {
            continue; //Try again!
         }
	 else
         {
            break; //Go back to terminal choice
         }
      }
   } 
   return 0;
}
//This function gets the info for the service record. Passes in member id and provider id
bool fillServiceRecord(string id_num, string providerId)
{
   //when validated, enter
   //Date of Service: MM-DD-YYYY
   //Look up 6 digit service code in directory
   //Provider keys in service code
   //Display name of the service corresponding to the code
   //Provider verifies this is the correct code
   //If non-existent code entered, error message is printed
   //Provider can then enter comments about the service
   //
   //Software writes:
   //Current date & time(MM-DD-YYYY HH:MM:SS)
   //Date of service(MM-DD-YYYY)
   //provider number(9 digits)
   //member number(9 digits)
   //service code(6 digits)
   //comments (100 chars)(optional)
   //
   //Software looks up fee for service and displays to provider.
}

int runProviderReport(string id_num)
{
   return 0;
}

int useDirectory(string id_num)
{
   return 0;
}
