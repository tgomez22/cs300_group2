//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)


#include "personList.h"

personList::personList()
{
	table = new *pNode[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

personList::~personList()
{
//needs to be implemented.
}

int personList::authenticate()
{
}

int personList::providerFunctions()
{
}
int personList::managerFunctions()
{
}
