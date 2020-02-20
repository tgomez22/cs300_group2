//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)

#include "entityTable.h"


//Pointer arithmetic is used to initalize the array of entityNode pointers as the private data member. 
//At the end of initialization, the pointer is set back to the first element. 
entityTable::entityTable()
{
  table = new entityNode*[SIZE];

  for(int i = 0; i < SIZE; ++i)
  {
    *table++ = NULL;
  }

  table -= SIZE;
}

//UNDER CONSTRUCTION
entityTable::~entityTable()
{
  entityNode ** start = table;
  for(int i = 0; i < SIZE; ++i)
  {
    destroyEntity(start[i]); // calls destroy so it can be recursive
  }

}

//For the destructor
void entityTable::destroyEntity(entityNode *& to_destroy)
{
  if(!to_destroy->next)
  {
    delete to_destroy;
    to_destroy = NULL;
    return;
  }
  if(!to_destroy)
    return;
  destroyEntity(to_destroy->next);
  delete to_destroy;
  to_destroy = NULL;
  return;
}

//UNDER CONSTRUCTION
bool entityTable::add(const entity & toAdd)
{
  int index = getIndex(toAdd.getIdValue());

  if(!table[index])
  {
    table[index] = new entityNode();
    table[index]->ent = new entity(toAdd);//Copy constructor
    table[index]->next = NULL;
    //logical check should be here to change entityNode auth value


    return true;
  }

  else
  {
    entityNode * temp = table[index];

    while(temp && temp->ent->compare(toAdd) != 0)
    {
      temp = temp->next;
    }

    //doesnt exist in list so add
    if(!temp)
    {
      temp = table[index];
      table[index] = new entityNode;
      table[index]->ent = new entity(toAdd); //copy constructor
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


int entityTable::authenticate(const entity & toCheck)
{
  //check this fctn call
  int index = getIndex(toCheck.getIdValue());     

  if(!table[index])
    return 0;

  else
  {
    entityNode * temp = table[index];

    //while still in chain and not found person
    while(temp && temp->ent->compare(toCheck) != 0)
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

int entityTable::getIndex(int keyValue)
{
  int index = keyValue;
  index = index * MULTBY;

  index = index % SIZE;

  if(index < 0)
    index = -index;

      return index;

}

int entityTable::providerFunctions()
{

}
int entityTable::managerFunctions()
{
}
