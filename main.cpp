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

using namespace std;        //for standard I/O

//Include everything to make sure it all compiles
#include "data_structures/test/datacenter_test.h"

#include "interfaces/validation-term.h"
#include "interfaces/cuecat.h"

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
         cout << "unrecognized option, exiting" << endl;
         break;
     }
     return 0;
   }

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
 
   int exitCode = chooseTerm();

   cout << "Thank you for using ChocAn.\n";
   cout << "Goodbye and have a nice day!\n\n";

   return exitCode;
}
