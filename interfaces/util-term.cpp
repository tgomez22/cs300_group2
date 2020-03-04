#include <stdio.h>          
#include <iostream>
#include <string.h>         

#include "util-term.h"

using namespace std;

int menu(string menuText, string* choices, int (* dispatchTable[])(), int numOfChoices) {
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
