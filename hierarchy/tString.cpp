#include "tString.h"
#include <cstring>
tString::tString()
{
	array = NULL;
}

tString::tString(char * toAdd)
{

	if(!toAdd)
		array = NULL;
	else
	{
		array = new char[strlen(toAdd) + 1];
		strcpy(array, toAdd);
	}
}

tString::tString(const tString & toAdd)
{
	if(!toAdd.array)
		array = NULL;
	else
	{
		array = new char[strlen(toAdd.array) + 1];
		strcpy(array, toAdd.array);
	}

}

tString::~tString()
{
	if(array)
		delete [] array;
	array = NULL;
}

int tString::compare(char * toCompare)const
{
	return strcmp(array, toCompare);
}

int tString::compare(const tString & toCompare)const
{
	return strcmp(array, toCompare.array);
}

bool tString::add(char * toAdd)
{
	if(array)
		return false;

	else
	{
		array = new char[strlen(toAdd) + 1];
		strcpy(array, toAdd);
		return true;
	}
}
bool tString::add(const tString & toAdd)
{
	if(array)
		return false;

	else
	{
		array = new char[strlen(toAdd.array) + 1];
		strcpy(array, toAdd.array);
		return true;
	}
}
