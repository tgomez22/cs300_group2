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
   tString ID;

   char * id = new char[id_num.length() +1];
   strcpy(id, id_num.c_str());

   ID.add(id);

   int numChoices = 5;

   string choices[numChoices] = {"Create Service Record", "Run Reports", 
	                         "Use Directory", "Quit", "Exit Program"};

   int (* dt[numChoices])(tString) = {createServiceRecord, runProviderReport, useDirectory,
	                               returnExitValue2, exitFunction2};

   while(true)
   {
      int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, ID);
      if(returnCode == EXITVALUE)
      {
         return 0;
      }
   }

   if(id)
      delete id;

   return 0;
}

int createServiceRecord(tString id_num)
{
   char tryAgain = '\0';
   tString m_ID;
   string mem_id_num;
   char * mem_id;
   bool successOrFail = false;

   while(true)
   {
      cout << "\nYou must now enter a Member ID in order\n";
      cout << "  to create a service record.\n\n";
      
      mem_id_num = getId();
      if(mem_id_num == "")
      {
         break;
      }
      if(datacenter::instance()->validateMember(mem_id_num))
      {
         mem_id = new char[mem_id_num.length() +1];
         strcpy(mem_id, mem_id_num.c_str());

         m_ID.add(mem_id);
        
	 successOrFail = fillServiceRecord(m_ID, id_num);
	 if(successOrFail == false)
         {
            cout << "Error adding service record.\n";
         }
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
    
   if(mem_id)
      delete mem_id;
   return 0;
}
//This function gets the info for the service record. Passes in member id and provider id
bool fillServiceRecord(tString mem_id_num, tString id_num)
{
   servRecInfo my_serv_rec;
   service my_service;
   char temp[3];
   temp[0] = 'N';
   temp[1] = 'A';
   temp[2] = '\0';

   my_serv_rec.currentDateTime.add(temp);
   my_serv_rec.providerID.add(temp);
   my_serv_rec.providerName.add(temp);
   my_serv_rec.memID.add(temp);
   my_serv_rec.memberName.add(temp);
   my_serv_rec.servDate.add(temp);
   my_serv_rec.servDescr.add(temp);
   my_serv_rec.servFee = 0.0;
   my_serv_rec.commentField.add(temp);

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
   bool successOrFail = false;
   bool goodToGo = false;


   cout << "\nThe Provider ID for this record is: ";
   id_num.display();
   cout << endl;
   cout << "The Member ID for this record is: ";
   mem_id_num.display();
   cout << endl;
   
   //Enter date of service in proper format
   do{
      cout << "\nEnter the month of service: (ex. enter 04 for April) " << endl;
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

   my_serv_rec.providerID.add(id_num);
   my_serv_rec.memID.add(mem_id_num);
   my_serv_rec.servDate.add(service_date);
   my_serv_rec.servCode.add(serviceCode);
   my_serv_rec.servDescr.add("TO ADD DESCRP");
   if(comments[0] != '\0')
      my_serv_rec.commentField.add(comments);

   successOrFail = datacenter::instance()->fillServiceRec(my_serv_rec);

   if(successOrFail)
   {   
      return true;
   }
   else
      return false;

}

int runProviderReport(tString id_num)
{
   return 0;
}

int useDirectory(tString id_num)
{
   service my_service;

   cout << "***************************************************\n";
   cout << "DIRECTORY INFORMATION\n";
   cout << "***************************************************\n";

   my_service.displayProviderDirectory();
   
   cout << "\n***************************************************\n";
  
   return 0;
}
