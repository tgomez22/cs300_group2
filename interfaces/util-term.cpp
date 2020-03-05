#include <stdio.h>          
#include <iostream>
#include <string.h>         

#include "util-term.h"

using namespace std;

  int menu(string menuText, string* choices, int (* dispatchTable[])(), int numOfChoices)
  {
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
     cleanupCin();
     }

     return dispatchTable[choice - 1]();
  }


//menu if you need to pass in strings and return ints for function pointer dt
  int menu2(string menuText, string* choices, int (* dispatchTable[])(string id_num), int numOfChoices)
  {
     int choice = 0;
     int tableResponse = 0;
     string id_num;

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
     cleanupCin();
     }

     return (dispatchTable[choice - 1](id_num));
  }

//a function to make sure the user wants to exit, then quit. 
//Returns 0 if the user does not, and exit() if the user does
//Can be used with a while loop to create automatically backing-out menus.
int exitFunction()
{
   char toQuit = 'n';      //This will determine if the user wants to quit

   cout << "Are you sure you want to quit? Y/N?\n";

   cin >> toQuit;
   cleanupCin();

   toQuit = tolower(toQuit);

   if(toQuit == 'y')
   {
     cout << "Thank you for using ChocAn.\n";
     cout << "Goodbye and have a nice day!\n\n";
     exit(0);
   }
   else
   {
     return 0;
   }
}

int exitFunction2(string id_num)
{
   char toQuit = 'n';      //This will determine if the user wants to quit

   cout << "Are you sure you want to quit? Y/N?\n";

   cin >> toQuit;
   cleanupCin();

   toQuit = tolower(toQuit);

   if(toQuit == 'y')
   {
     cout << "Thank you for using ChocAn.\n";
     cout << "Goodbye and have a nice day!\n\n";
     exit(0);
   }
   else
   {
     return 0;
   }
}

//Based on this answer from stack overflow:
//https://stackoverflow.com/a/19469949
void cleanupCin() {
  cin.ignore(100, '\n');
  if(!cin) {
    cin.clear();
    if(cin) {
      cin.ignore(100, '\n');
    }
  }
}

int returnExitValue() {
  return EXITVALUE; 
}

int returnExitValue2(string id_num) {
  return EXITVALUE; 
}
