//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)


#include "personList.h"


//Pointer arithmetic is used to initalize the array of personNode pointers as the private data member. 
//At the end of initialization, the pointer is set back to the first element. 
personList::personList()
{
  table = new *personNode[SIZE];

  for(int i = 0; i < SIZE; ++i)
  {
    *table++ = NULL;
  }

  table -= SIZE;
}

//UNDER CONSTRUCTION
personList::~personList()
{
  personNode ** start = table;
  for(int i = 0; i < SIZE; ++i)
  {
    destroyPerson(start[i]); // calls destroy so it can be recursive
  }

}

//For the destructor
void personList::destroyPerson(personNode *& to_destroy)
{
  if(!to_destroy->next)
  {
    delete to_destroy;
    to_destroy = NULL;
    return;
  }
  if(!to_destroy)
    return;
  destroyPerson(to_destroy->next);
  delete to_destroy;
  to_destroy = NULL;
  return;
}

//UNDER CONSTRUCTION
bool personList::add(const entity & toAdd)
{
  int index = getIndex(toAdd.getIdValue());

  if(!table[index])
  {
    table[index] = new personNode;
    table[index]->person.addId(toAdd);
    table[index]->next = NULL;
    //logical check should be here to change personNode auth value



    return true;
  }

  else
  {
    personNode * temp = table[index];

    while(temp && temp->person.compare(toAdd) != 0)
    {
      temp = temp->next;
    }

    //doesnt exist in list so add
    if(!temp)
    {
      temp = table[index];
      table[index] = new personNode;
      table[index]->person.addId(toAdd);
      table[index]->next = temp;
      return true;
    }

    //if Duplicate then dont add
    else
    {
      return false;
    }


  }
}


int personList::authenticate(const entity & toCheck)
{
  //check this fctn call
  int index = getIndex(toCheck.getIdValue());     

  if(!table[index])
    return 0;

  else
  {
    personNode * temp = table[index];

    //while still in chain and not found person
    while(temp && temp->person.compare(toCheck) != 0)
    {
      temp = temp->next;
    }

    //place holder for person not found
    if(!temp)
      return 0;

    //person is found
    else
    {
      return temp->authority; 
    }
  }
}

int personList::getIndex(int keyValue)
{
  int index = keyValue;
  index = index * MULTBY;

  index = index % SIZE;

  if(index < 0)
    index = -index;

      return index;

}

int personList::providerFunctions()
{

}
int personList::managerFunctions()
{

}
