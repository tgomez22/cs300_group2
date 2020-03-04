//CS300 - Group 2 Project
//This file needs a description!!!
//
//
#include <time.h>
#include <iostream>
#include "service.h" 
#include "../model/tString.h"
service::service()
{
  time_t numberTime;
  time(&numberTime); //This puts a number in numberTime of current time. (you don't have to enter the time of day. It automatically 
                      //tells you at allocation
  next = NULL;
  servFee = 0.0;

}

service::service(const service & toAdd)
{
  dos.add(toAdd.dos);
  numberTime = toAdd.numberTime;
  servName.add(toAdd.servName);
  memName.add(toAdd.memName);
  provName.add(toAdd.provName);
  servCode.add(toAdd.servCode);
  servFee = toAdd.servFee;
  next = NULL;

}

//read in function for terminal folks. I (TRISTAN) filled this in for testing
//feel free to change it. It assumes correct input at this time. needs "guards".
void service::addService()
{
    using namespace std;
    
    char userChoice;
    
    char dateOfService[INPUT];
    char memberName[INPUT];
    char providerName[INPUT];
    char serviceCode[INPUT];
    char serviceName[INPUT];
    int feeDue = 0;
    
    cout<<"Please enter the date of service in mm/dd/yyyy: ";
    cin.get(dateOfService, INPUT, '\n');
    cin.ignore(100, '\n');
    dos.add(dateOfService);

    cout<<"What is the name of the member who received the service?: ";
    cin.get(memberName, INPUT, '\n');
    cin.ignore(100, '\n');
    memName.add(memberName);

    cout<<"Who provided the service?: ";
    cin.get(providerName, INPUT, '\n');
    cin.ignore(100, '\n');
    provName.add(providerName);

    cout<<"Would you like to see a directory of services? Y or N: ";
    cin>>userChoice;
    cin.ignore(100, '\n');

    if(userChoice == 'y' || userChoice == 'Y')
    {
        //placeholder.
    }
    
    cout<<"What is the numerical code of the service?: ";
    cin.get(serviceCode, INPUT, '\n');
    cin.ignore(100, '\n');
    servCode.add(serviceCode);

    cout<<"What is the name of the service being provided?: ";
    cin.get(serviceName, INPUT, '\n');
    cin.ignore(100, '\n');
    
    cout<<"What was the cost of the service?: ";
    cin>>feeDue;
    cin.ignore(100, '\n');

    servFee = feeDue;

    return;

}

service::~service()
{

}

void service::display(void) const
{
    using namespace std;
  cout << "date of service: ";
  dos.display();
  cout << endl;

  cout << "Service name: ";
  servName.display() ;
      cout<< endl ;

      cout << "Member name: ";
      memName.display();
      cout<< endl;

      cout<< "Provider name: ";
      provName.display();
      cout<<endl;
      cout << "service code: ";
      servCode.display();
      cout<< endl;
      cout << "service fee: ";
      cout<< servFee << endl;
}

void service::displayTime(void)
{
    using namespace std;
  time(&numberTime);
  cout << "Current time is: " << ctime(&numberTime);

}

//ABBIE!!! I commented these out because curr_time doesnt
//seem to exist in this class as a data member. Maybe it got 
//deleted???
void service::convertDate(time_t & toConvert)
{
    
  //toConvert = curr_time;
  //time(&curr_time);
  
  //dos(ctime(&curr_time));

  return;
}

//ABBIE!!! table exists in service list. Most of this code should be moves there.
int service::getWeek()
{
    using namespace std;
  time_t timeToGet;
  time(&timeToGet);

  timeToGet -= 604800;

  cout << "This was a week ago: " << ctime(&timeToGet);
 


  //to find everything that was a week ago:
  //search through the table to find the service that matches the date
  /*
   *
  for(int i = 0; i < SIZE; ++i)
  {
    if(table[i])
    {
      service * current = new service;
      current = table[i]->head;
      while(current)
      {
        if(table[i]->head.numberTime >= timeToGet)
          //put this in the report function? For now we will just display???
          //reports peeps call your function here? Or something of that
          table[i]->head.display();
          current = current->next;
      }
    }
  }
  */
}

service *& service::toNext()
{
    return next;
}

//This function will display all the "stored providers". I am hard coding this in 
//for now. I can't think of a good place to put this. I may consider making this char**
//a private data member. 
void service::displayProviderDirectory()const
{
    using namespace std;
    //Change this to affect rest of function.
    int directorySize = 2;


    //magic number place holder.
  char providerDirectory [directorySize][SIZE] = {"Dietitian (598470) ", "Aerobics Exercise Session (883948)"};
    

  for(int i = 2; i < directorySize; ++i)
  {
        cout<<"Service: "<<providerDirectory[i]<<endl;
  }

  return;



}


