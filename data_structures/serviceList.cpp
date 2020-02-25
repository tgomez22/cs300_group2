#include "serviceList.h"

serviceList::serviceList()
{
	table = new sNode[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

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
}

int serviceList::memberFunctions()
{

}

int serviceList::getKey(const int toUse)
{
	int key = toUse * MULTBY;
	key = key % SIZE;

    if(key < 0)
        key = -key;

	return key;
}


///check logic again???
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
        
        //fell off list, member doesn't exist
		if(!temp)
		{
			//must be an existing member to add a service.
			return false;
		}
        
        //found member, adding service
		else
		{
			service * headHolder = temp->head;
			temp->head = new service(toAdd);
			temp->head.to_next() = headHolder;
			return true;

		}
	}

}
