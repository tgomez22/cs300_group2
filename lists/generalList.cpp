//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)


#include "generalList.h"

generalList::generalList()
{
	table = new *gNode[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

generalList::~generalList()
{
//needs to be implemented.
}
