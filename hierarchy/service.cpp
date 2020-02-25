#include <time.h>
#include <iostream>
#include "service.h"
using namespace std;

service::service();
{
  time_t numberTime;
  time(&numberTime); //This puts a number in numberTime of current time. (you don't have to enter the time of day. It automatically 
                      //tells you at allocation

}

service::service(const service & toAdd)
{
  dos(toAdd.dos);
  numberTime = toadd.numberTime;
  servName(toAdd.servName);
  memName(toAdd.memName);
  serviceCode(toAdd.serviceCode);
  serviceFee = toAdd.serviceFee;
  next = NULL;

}

service::~service()
{

}

void service::display(void) const
{
  cout << "date of service: " << dos.display() << endl 
      << "Service name: " << servName.display() << endl 
      << "Member name: " << memName.display() << endl
      << "service code: " << servCode.display() << endl
      << "service fee: " << serviceFee << endl << endl;
}

void service::displayTime(void)
{
  time(&numberTime);
  cout << "Current time is: " << ctime(&numberTime);

}

void service::convertDate()
{
  time_t = curr_time;
  time(&curr_time);
  
  dos(ctime(&curr_time));

  return;
}


int service::getWeek()
{
  time_t timeToGet;
  time(&timeToGet);

  timeToGet -= 604800;

  cout << "This was a week ago: " << ctime(&timeToGet);
  
  //to find everything that was a week ago:
  //search through the table to find the service that matches the date
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
}
