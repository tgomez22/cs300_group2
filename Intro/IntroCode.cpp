#include <iostream>         //for normal I/O functionality
#include <cstring>          //for string functions like tolower/toupper, etc.

using namespace std;        //for standard I/O

const int EXITVALUE = 99;   //exit value to exit the program

void welcomeFunction();     //Function to welcome the user
int chooseIDEnter();        //for the user to choose how to enter the ID information
int exitFunction();         //a function to make sure the user wants to exit
void thankYouGoodbye();     //Function to thank the user for using ChocAn


int main()
{
   int menuChoice = 0;      //To catch which menu item the user wants
   int keepGoing = 0;       //To determine if the user wants to continue

   welcomeFunction();       //To welcome the user/give credit

   //Do these things while the user does NOT want to exit; ie keepGoing is NOT EXITVALUE
   do
   {
      menuChoice = chooseIDEnter();
      if(menuChoice == 0)
      {
	      //run menu choice again, invalid input
	      keepGoing = 0;
      }
      else if(menuChoice == 1 || menuChoice == 2)
      {
	      //the scan has taken place...functions haven't been incorporated yet
	      cout << "We are in the input section.\n";
	      keepGoing = 0;
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