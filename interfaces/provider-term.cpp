#include "provider-term.h"

#include <iostream>
#include <string>
#include <string.h>  //for strcat
#include <stdio.h>   //for strcat

#include "../datacenter.h"
#include "util-term.h"
#include "validation-term.h"
#include "../hierarchy/service.h"

using namespace std;

const int DATESZ = 11;
const int MONTHSZ = 3;
const int YEARSZ = 5;
const int SCODESZ = 7;
const int COMMSZ = 101;


//providerTerm assumes that the provider id number has already been validated
//then it provides the menu options for the provider
int providerTerm(string id_num)
{
   int numChoices = 5;

   string choices[numChoices] = {"Create Service Record", "Run Reports", 
	                         "Use Directory", "Quit", "Exit Program"};

   int (* dt[numChoices])(string) = {createServiceRecord, runProviderReport, useDirectory,
	                               returnExitValue2, exitFunction2};

   while(true)
   {
      int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, id_num);
      if(returnCode == EXITVALUE)
      {
         return 0;
      }
   }

   return 0;
}

int createServiceRecord(string id_num)
{
   char tryAgain = '\0';

   while(true)
   {
      cout << "\nYou must now enter a Member ID in order\n";
      cout << "  to create a service record.\n\n";
      string mem_id_num = getId();
      if(mem_id_num == "")
      {
         break;
      }
      if(datacenter::instance()->validateMember(mem_id_num))
      {
         fillServiceRecord(mem_id_num, id_num);
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
bool fillServiceRecord(string mem_id_num, string id_num)
{
   service my_service;
   char service_date_m[MONTHSZ];
   char service_date_d[MONTHSZ];
   char service_date_y[YEARSZ];
   char service_date[DATESZ];
   char serviceCode[SCODESZ];
   char comments[COMMSZ];
   char answerYN = 'n';
   char lookUpInDir = 'n';
   int keepGoing = 0;
   int keepGoing2 = 0;
   int keepGoing3 = 0;
   int keepGoing4 = 0;

   cout << "\nThe Provider ID for this record is: " << id_num << endl;
   cout << "The Member ID for this record is: " << mem_id_num << endl;
   
   //Enter date of service in proper format
   do{
      cout << "Enter the month of service: (ex. enter 04 for April) " << endl;
      cin.get(service_date_m, MONTHSZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Enter the day of service: (ex. enter 17) " << endl;
      cin.get(service_date_d, MONTHSZ, '\n');
      cin.ignore(SIZE, '\n');

      cout << "Enter the year of service: (ex. enter 2020) " << endl;
      cin.get(service_date_y, YEARSZ, '\n');
      cin.ignore(SIZE, '\n');

      strcpy(service_date, service_date_m);
      strcat(service_date, "-");
      strcat(service_date, service_date_d);
      strcat(service_date, "-");
      strcat(service_date, service_date_y);
      
      cout << "You entered: " << service_date << endl;
      cout << "Is this correct? y/n " << endl;
      cin >> answerYN;
      cin.ignore(SIZE, '\n');

      answerYN = tolower(answerYN);
      if(answerYN == 'y')
      {
         keepGoing = 1;
      }
      else
      {
         keepGoing = 0;
      }
   }while(keepGoing == 0);

   do{
      cout << "\nNow you need to enter a service code.\n";
      cout << "Do you need the service directory to find the code? (y/n) \n";
      
      cin >> lookUpInDir;
      cin.ignore(SIZE, '\n');

      lookUpInDir = tolower(lookUpInDir);
      if(lookUpInDir == 'y')
      {
         //then go to directory function
	 my_service.displayProviderDirectory();
      }
    
      cout << "\nPlease enter the 6-digit service code number (ex. 112233)\n";
      cin.get(serviceCode, SCODESZ, '\n');
      cin.ignore(SIZE, '\n'); 

      cout << "You entered: " << serviceCode << endl;

      cout << "\nThe service corresponding to the code you entered is: \n";
      //run display service function serviceDescription(serviceCode)
      cout << "FUNCTIONALITY TO COME\n";

      cout << "Is this information correct? (y/n)\n";
      cin >> answerYN;
      cin.ignore(SIZE, '\n');

      answerYN = tolower(answerYN);
      if(answerYN == 'y')
      {
         keepGoing2 = 1;
      }
      else
      {
         keepGoing2 = 0;
      }

   }while(keepGoing2 == 0);
     
   do{

      for(int i=0; i<COMMSZ; ++i)
      {
         comments[i] = '\0';
      }

      cout << "\nWould you like to add comments about this session? (y/n) \n";
      cin >> answerYN;
      cin.ignore(SIZE, '\n');

      answerYN = tolower(answerYN);
      if(answerYN == 'y')
      {
         do{
            cout << "\nPlease enter your comments (up to 100 characters): \n";
	    cin.get(comments, COMMSZ, '\n');
	    cin.ignore(SIZE, '\n');

	    cout << "\nYou entered the following comments. Correct y/n? \n";
	    cout << comments << endl;
	    cin >> answerYN;
	    cin.ignore(SIZE, '\n');

            answerYN = tolower(answerYN);
            if(answerYN == 'y')
	    {
	       keepGoing4 = 1;
            }
            else
	    {
	       keepGoing4 = 0;
            }	       
	 }while(keepGoing4 == 0);
	 
	 if(keepGoing4 != 0)
            keepGoing3 = 1;
      }
      else
      {
         keepGoing3 = 1;
      } 
   }while(keepGoing3 == 0);

   cout << "***************************************************\n";
   cout << "This is the information for this record: \n";
   cout << "***************************************************\n";
   cout << "Current Date & Time: "; my_service.displayTime();
   cout << "Service Date: " << service_date << endl;
   cout << "Provider Number: " << id_num << endl;
   cout << "Provider Name: " << "TO COME..." << endl;
   cout << "Member Number: " << mem_id_num << endl;
   cout << "Member Name: " << "TO COME..." << endl;
   cout << "Service Code: " << serviceCode << endl;
   cout << "Service Description: " << "TO COME...my_service.serviceDescription(CODE)" << endl;
   cout << "Comments: " << comments << endl;
   cout << "Service Fee: " << "TO COME...my_service.serviceFee(CODE)" << endl << endl;
   cout << "***************************************************\n";
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
   service my_service;

   cout << "***************************************************\n";
   cout << "DIRECTORY INFORMATION\n";
   cout << "***************************************************\n";

   my_service.displayProviderDirectory();
   
   cout << "\n***************************************************\n";
  
   return 0;
}
