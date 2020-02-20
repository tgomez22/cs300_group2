//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)


#include "entity_table.h"

entityTable::entityTable()
{
	table = new *gNode[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

entityTable::~entityTable()
{
//needs to be implemented.
}
