//This is the main interface area for the ChocAn
//simulator system version 1.0. This was created for CS300 with
//Instructor Chris Gilmore. The student development
//team consists of: Kristin Bell, Chris Childs,
//Tristan Gomez, Mikayla Maki, Shawn Spears, and
//Abbie Utley. We are group 2, Winter term 2020.
//
//This program is outlined in the documentation
//that was submitted, but briefly, it is a computer
//system that allows ChocAn providers and managers
//to add and access information about patients and
//provider services at ChocAn, an organization that
//helps members combat chocolate addiction.
//
//


#define CATCH_CONFIG_RUNNER //for catch testing framework
#include "testing/catch.hpp"//for catch testing framework
#include <iostream>         //for normal I/O functionality
#include <cstring>          //for string functions like tolower/toupper, etc.
#include <stdlib.h>         //for CueCat code
#include <stdio.h>          //for CueCat code
#include <string.h>         //for CueCat code
#include <assert.h>         //for CueCat code

#define BUF_SIZE 1024       //for CueCat code
#define XOR 'C'             //for CueCat code

const char *sequence = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-";   //for CueCat
const char *base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";     //for CueCat

using namespace std;        //for standard I/O

//Include everything to make sure it all compiles

//datacenter.h no longer exists
//entity.h no longer exists
//#include "data_structures/datacenter.h"
//#include "data_structures/entityTable.h"



#include "data_structures/serviceList.h"
#include "data_structures/personList.h"
#include "model/entity.h"
#include "hierarchy/service.h"
#include "model/person.h"
#include "model/member.h"
#include "model/provider.h"

#include "data_structures/test/datacenter_test.h"


const int EXITVALUE = 99;   //exit value to exit the program

static char *getData(const char *input);  //For CueCat code to get data
static char *decode(char *in);            //For CueCat decodes the data

int menu(char* menuText, char** choices, int (* dispatchTable[])(), int numOfChoices);

bool getCueCat(entity & one_user);        //For CueCat runs the other functions
void welcomeFunction();     //Function to welcome the user
int chooseIDEnter();        //for the user to choose how to enter the ID information
int exitFunction();         //a function to make sure the user wants to exit
void thankYouGoodbye();     //Function to thank the user for using ChocAn
int scanId();
int typeId();            //Function to get one member ID by typing

int main(int argc, char* argv[])
{
   //Bypass all our terminal stuff for testing
   if(argc >= 2) {
     char* test = argv[1];
     switch(test[0]) {
       case 'd':
         datacenterTest();
         break;	
       case 't':
         return Catch::Session().run(); //Calls tests in testing/tests.cpp
         //If you want to make more testing files, just add more cases and call whatever you want.
         //I've used single letters to keep things simple, just run ./ChocAn [letter] and then add [letter]
         //To this switch statement, and set it to call whatever you need. That way we can run tests
         //Without going through the entire terminal setup
       default:
         cout << "unrecognized test, exiting" << endl;
         break;
     }
     exit(0);
   }

   welcomeFunction();       //To welcome the user/give credit

   char* choices[3] = {new char, new char, new char};
   strcpy(choices[0], "Scan ID number");
   strcpy(choices[1], "Type ID number");
   strcpy(choices[2], "Quit");
   int (* dt[3])() = {scanId, typeId, exitFunction};
   int checkValue = 0;

   checkValue = menu("Choose from the following:", choices, dt, 3);
   if(checkValue == EXITVALUE)
   {
      thankYouGoodbye();
      return 0;
   }
   else
      return 0;
}

int menu(char* menuText, char** choices, int (* dispatchTable[])(), int numOfChoices) {
  int choice = 0;
  int tableResponse = 0;

  cout << menuText << endl;
  for(int i = 0; i < numOfChoices; ++i) {
    cout << i + 1 << ". " << choices[i] << endl;
  }
  cin >> choice;
  cin.ignore(100, '\n');
  
  //Users acceptable inputs are [1..numOfChoices]
  while(choice < 1 || choice > numOfChoices) {
    cout << "Choice is invalid, please enter a number between 1 and " << numOfChoices << " (inclusive)." << endl;
    cin >> choice;
    cin.ignore(100, '\n');
  }

  tableResponse = dispatchTable[choice - 1]();

  if(tableResponse == EXITVALUE)
  {
     return EXITVALUE;
  }
  else
     return 0;
}

//Function to welcome the user/give credits
void welcomeFunction()
{
   cout << "*******************************************\n";
   cout << "* Welcome to the ChocAn Simulator (v.1.0) *\n";
   cout << "*******************************************\n\n";

   cout << "Development Team for CS300\nwith Chris Gilmore:\n\n";
   cout << "Kristin Bell\n";
   cout << "Chris Childs\n";
   cout << "Tristan Gomez\n";
   cout << "Mikayla Maki\n";
   cout << "Shawn Spears\n";
   cout << "and Abbie Utley\n\n\n";

   return;

}


//TODO re-add this functionality
//a function to make sure the user wants to exit
int exitFunction()
{
   char toQuit = 'n';      //This will determine if the user wants to quit
   int exitChoice = 0;     //The choice to quit will be sent back as an EXITVALUE if they want to quit, otherwise 0

   cout << "Are you sure you want to quit? Y/N?\n";

   cin >> toQuit;
   cin.ignore(100,'\n');

   toQuit = tolower(toQuit);

   if(toQuit == 'y')
   {
      exitChoice = EXITVALUE;
   }
   else if(toQuit == 'n')
   {
      exitChoice = 0;
   }
   else
   {
      exitChoice = 0;
   }

   return exitChoice;

}

//Function to thank user for usning ChocAn
void thankYouGoodbye()
{
   cout << "Thank you for using ChocAn.\n";
   cout << "Goodbye and have a nice day!\n\n";
   return;
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
   return 0;
}


int typeId()
{
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

   checkValue = one_user.addIdFromTerm();

   if(checkValue == false)
   {
      cout << "Sorry. That does not work. Try again.\n";
      errorValue = 0;
   }
   else
   {
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
   //change return value before deployment!!!
   return 0;
}
/*int isOrNotSuspended(entity & one_user, serviceList & my_service_list)
{


}
*/

//Edited by Kristin Bell for use with ChocAn System
/*
 * CueCat Decoder
 *
 * Thanks to:
 *   - http://oilcan.org/cuecat/base64.html
 *   - LibraryThing for shipping my CueCat
 *
 * Copyright (c) 2009 Ricardo Martins <ricardo@scarybox.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
 * Returns just the barcode data, ignoring the CueCat's serial number and the
 * type of the barcode
 */
static char *getData(const char *input)
{
   int nSeen;
   char *data;
   const char *pos = NULL;

   for (nSeen = 0; *input != '\0'; input++) {
      if (*input == '.') {
         nSeen++;
         if (nSeen == 3)
            pos = input + 1;
      }
   }

  // assert(pos != NULL);

   if(pos != NULL)
   {
      size_t size = input - pos - 1;

      data = (char *)calloc(size+1, sizeof(char));

      strncpy(data, pos, size);
   }
   else
   {
      size_t size2 = 1;
      data = (char *)calloc(size2, sizeof(char));
      data[0] = 'x';
   }

   return data;
}

/* Decodes the data encrypted by the CueCat */
static char *decode(char *in)
{
   int i, j;
   size_t length = strlen(in) % 4;
   char * decoded;

   decoded = (char *)calloc(100, sizeof(char));

   if (length != 0)
      length = 4 - length;

   for (i = 0; i < strlen(in); i++) {
      for (j = 0; in[i] != sequence[j]; j++);
      in[i] = j;
   }

   for (i = 0, j = 0; i < strlen(in); i += 4) {
      int tmp = ((in[i] << 6 | in[i+1]) << 6 | in[i+2]) << 6 | in[i+3];
      decoded[j++] = (tmp >> 16) ^ XOR;
      decoded[j++] = (tmp >> 8 & 255) ^ XOR;
      decoded[j++] = (tmp & 255) ^ XOR; // in[i+3]^XOR
   }

   memset(decoded+strlen(decoded) - length, 0, length);

   return decoded;
}

bool getCueCat(entity & one_user)
{
   char *input, *data, *decoded;
        input = (char *)calloc(255, sizeof(char));

   bool checkValue = false;
   bool errorValue = false;

   scanf("%254s", input);

   data = getData(input);
   decoded = decode(data);
   printf("%s\n", decoded);

   checkValue = one_user.checkIdFromScan(decoded);

   if(checkValue == false)
   {
      errorValue = false;
   }
   else
   {
      errorValue = true;
   }

   free(input);
   free(data);
   free(decoded);

   return errorValue;
}

// vim: et ts=4 sw=4 sts=4
