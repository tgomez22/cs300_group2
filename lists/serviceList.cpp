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
