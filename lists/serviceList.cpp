#include "serviceList.h"
#include "service.h"
#include "entity.h"
#include "person.h"
#include "provider.h"
#include "member.h"
#include <ctime>
#include <cstdlib>
using namespace std;
const int ID = 10;
const int SIZE = 101;
const int MULTBY = 97;

int getWeek()
{
  time_t timeToGet;
  timeToGet = NULL;

  timeToGet -= 604800;
  time(&timeToGet);

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
