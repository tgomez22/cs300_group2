#include "serviceList.h"
<<<<<<< HEAD

serviceList::serviceList()
{
	table = new sNode[SIZE];
=======
#include "service.h"
#include "entity.h"
#include "person.h"
#include "provider.h"
#include "member.h"
#include <cstdlib>
const int ID = 10;
const int SIZE = 101;
const int MULTBY = 97;
serviceList::serviceList()
{
	table = new serviceNode*[SIZE];
>>>>>>> master

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

<<<<<<< HEAD
//UNDER CONSTRUCTION
serviceList::~serviceList()
{
  serviceNode ** start = table;
  for(int i = 0; i < 0; ++i)
  {
    destroyService(start[i]);
  }
}

void destroyService(serviceNode *& to_destroy)
{
  if(!to_destroy->next)
  {
    to_destroy->head.~service();
    delete to_destroy;
    to_destroy = NULL;
    return;
  }
  if(!to_destroy)
    return;
  to_destroy->head.~service();
  deleteServices(to_destroy->head);
  delete to_destroy;
  to_destroy = NULL;
  return;
=======
serviceList::~serviceList()
{
    for(int i = 0; i < SIZE; ++i)
    {
        if(table[i])
        {
            removeNodes(table[i]);
        }
    }

    delete [] table;
    table = NULL;
}

void serviceList::removeNodes(serviceNode *& toRemove)
{
    if(!toRemove)
        return;

    removeNodes(toRemove->next);

    delete toRemove->aPerson;
    toRemove->aPerson = NULL;
    removeServices(toRemove->head);
    toRemove->head = NULL;

    return;

}

void serviceList::removeServices(service *& toRemove)
{
    if(!toRemove)
        return;

    removeServices(toRemove->toNext());
    delete toRemove;
    toRemove = NULL;

    return;

>>>>>>> master
}

int serviceList::memberFunctions()
{

}

<<<<<<< HEAD
=======
int serviceList::addPerson(const person & toAdd)
{

    int index = getKey(toAdd.getIdValue());

    if(!table[index])
    {
        table[index] = new serviceNode;

        const member * ptr = dynamic_cast<const member*>(&toAdd);
        if(ptr)
        {
            table[index]->aPerson = new member(*ptr);
            table[index]->head = NULL;
            table[index]->next = NULL;
            return 1;
        }

        else
        {
            const provider * ptr2 = dynamic_cast<const provider*>(&toAdd);
            if(ptr2)
            {
                table[index]->aPerson = new provider(*ptr2);
                table[index]->head = NULL;
                table[index]->next = NULL;
                return 1;
            }

            return 0;
        }


    }

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toAdd) != 0)
        {
            temp = temp->next;
        }

        //fell off the list so no duplicate. add at head.
        if(!temp)
        {
            temp = table[index];

            table[index] = new serviceNode;

            const member * ptr3 = dynamic_cast<const member*>(&toAdd);
            if(ptr3)
            {
                table[index]->aPerson = new member(*ptr3);
                table[index]->head = NULL;
                table[index]->next = temp;
                return 1;
             }

            else
            {
                const provider * ptr4 = dynamic_cast<const provider*>(&toAdd);
                if(ptr4)
                {
                    table[index]->aPerson = new provider(*ptr4);
                    table[index]->head = NULL;
                    table[index]->next = temp;
                    return 1;
                }

                return 0;

            }
        }

        //duplicate found so return failure.

    }

}

>>>>>>> master
int serviceList::getKey(const int toUse)
{
	int key = toUse * MULTBY;
	key = key % SIZE;

    if(key < 0)
        key = -key;

	return key;
}


///check logic again???
<<<<<<< HEAD
bool serviceList::addService(const service & toAdd)
{
	int index = getKey(toAdd.getIdValue());

	if(table[index] == NULL)
	{
		table[index] = new sNode;
		table[index]->memNum.addId(toAdd);;
		table[index]->head = new service(toAdd);
		table[index]->next = NULL;

		return true;
	}

	else
	{
		sNode * temp = table[index];

		while(temp && temp->memNum.compare(toAdd)!= 0)
		{
			temp = temp->next;
		}

=======
bool serviceList::addService(const class service & toAdd)
{
	int index = getKey(toAdd.getIdValue());

	if(!table[index])
	{
		table[index] = new serviceNode;
		table[index]->aPerson->addId(toAdd);
		table[index]->head = new service(toAdd);
		table[index]->next = nullptr;

		return true;
	}

	else
	{
		serviceNode * temp = table[index];

		while(temp && temp->aPerson->compare(toAdd)!= 0)
		{
			temp = temp->next;
		}

>>>>>>> master
        //fell off list, member doesn't exist
		if(!temp)
		{
			//must be an existing member to add a service.
			return false;
		}
<<<<<<< HEAD

=======

>>>>>>> master
        //found member, adding service
		else
		{
			service * headHolder = temp->head;
			temp->head = new service(toAdd);
<<<<<<< HEAD
			temp->head.to_next() = headHolder;
=======
			temp->head->toNext() = headHolder;
>>>>>>> master
			return true;

		}
	}

}
