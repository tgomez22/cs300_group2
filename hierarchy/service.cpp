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
  serviceFee = 0;

}

service::service(const service & toAdd)
{
  dos.add(toAdd.dos);
  numberTime = toAdd.numberTime;
  servName.add(toAdd.servName);
  memName.add(toAdd.memName);
  serviceCode.add(toAdd.serviceCode);
  serviceFee = toAdd.serviceFee;
  next = NULL;

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
      cout << "service code: ";
      serviceCode.display();
      cout<< endl;
      cout << "service fee: ";
      cout<< serviceFee << endl;
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
