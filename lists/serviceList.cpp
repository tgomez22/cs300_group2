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

serviceList::~serviceList()
{
//need to implement
}

int serviceList::memberFunctions()
{

}

int serviceList::getKey(const int toUse)
{
	int key = toUse * MULTBY;
	key = key % SIZE;

	return key;
}


///check logic again???
bool serviceList::addService(const service & toAdd)
{
	int index = getKey(toAdd.getIdValue());	

	if(table[index] == NULL)
	{
		table[index] = new sNode;
		table[index].memNum.getMemId(toAdd);
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

		if(!temp)
		{
			//must be an existing member to add a service.
			return false;
		}

		else
		{
			service * headHolder = temp->head;
			temp->head = new service(toAdd);
			temp->head.to_next() = headHolder;
			return true;

		}
	}

}
