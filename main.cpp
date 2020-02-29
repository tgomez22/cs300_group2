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

#include "model/entity.h"
#include "hierarchy/service.h"
#include "model/person.h"
#include "model/member.h"
#include "model/provider.h"

#include "data_structures/test/datacenter_test.h"


const int EXITVALUE = 99;   //exit value to exit the program

static char *getData(const char *input);  //For CueCat code to get data
static char *decode(char *in);            //For CueCat decodes the data
bool getCueCat(entity & one_user);        //For CueCat runs the other functions
void welcomeFunction();     //Function to welcome the user
int chooseIDEnter();        //for the user to choose how to enter the ID information
int exitFunction();         //a function to make sure the user wants to exit
void thankYouGoodbye();     //Function to thank the user for using ChocAn
int scanId(entity & one_user);
int typeId(entity & one_user, serviceList & my_service_list);            //Function to get one member ID by typing

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

   int menuChoice = 0;      //To catch which menu item the user wants
   int keepGoing = 0;       //To determine if the user wants to continue
   int checkValue = 0;      //To check if ID was entered correctly

   welcomeFunction();       //To welcome the user/give credit

   entity one_user;         //Creates an instance of one user/entity
   member one_member;

   //person has virtual functions and is an abstract base class
   //C++ doesn't allow objects to be made of it.
   provider one_provider;
   service one_service;
   serviceList my_service_list;

   //Do these things while the user does NOT want to exit; ie keepGoing is NOT EXITVALUE
   do
   {
     menuChoice = chooseIDEnter();
     if(menuChoice == 0)
     {
	      //run menu choice again, invalid input
	      keepGoing = 0;
     }
     else if(menuChoice == 1)
     {
	      //if the scanId doesn't work go back to menu
     	  //otherwise do a different task
        checkValue = scanId(one_user);
	      if(checkValue == 0)
        {
            keepGoing = 0;
	      }
	      else
        {
            //do something else
        }
     }
     else if(menuChoice == 2)
     {
	      //if the typeId doesn't work go back to menu
	      //otherwise do a different task
        checkValue = typeId(one_user, my_service_list);
	      if(checkValue == 0)
	      {
           keepGoing = 0;
     	 }
	      else
        {
           //do something else
	      }
     }
     else if(menuChoice == EXITVALUE)
     {
	     //exit program;
	     keepGoing = EXITVALUE;
     }
     else
     {
	     cout << "Error. Try again.\n";
	     keepGoing = 0;
     }
  } while (keepGoing != EXITVALUE);

   thankYouGoodbye();
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



//for the user to choose how to enter the ID information
int chooseIDEnter()
{
   int choiceToEnter = 0;     //this holds the choice from the menu
   int choice = 0;            //this is the choice value that gets returned
   int exitChoice = 1;        //this holds the value of whether or not the user wants to exit

   cout << "Choose from the following:\n";
   cout << "1) Scan ID number\n";
   cout << "2) Type ID number\n";
   cout << "3) Quit\n";

   cin >> choiceToEnter;
   cin.ignore(100, '\n');

   if(choiceToEnter == 1)
   {
      //run scan function
      choice = 1;
   }
   else if(choiceToEnter == 2)
   {
      //run type function
      choice = 2;
   }
   else if(choiceToEnter == 3)
   {
      //run exit function. if they want to exit set choice to 99, otherwise set choice to 0 to retry
      exitChoice = exitFunction();
      if(exitChoice == EXITVALUE)
      {
         choice = EXITVALUE;
      }
      else if(exitChoice == 0)
      {
         cout << "Please try again.\n";
         choice = 0;
      }
   }
   else
   {
      cout << "Invalid choice. Please try again.\n";
      choice = 0;
   }

   return choice;
}

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

int scanId(entity & one_user)
{
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

   return errorValue;
}
   

int typeId(entity & one_user, serviceList & my_service_list)
{
   bool checkValue = false;
   int errorValue = 0;
   int isOnList = 3;
   bool didWriteWork = false;

   checkValue = one_user.addIdFromTerm();

   if(checkValue == false)
   {
      cout << "Sorry. That does not work. Try again.\n";
      errorValue = 0;
   }
   else
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

   return errorValue;
}

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
