#include "tString.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
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


char * tString::getString()
{
    if(array)
    {
        char * temp = new char[strlen(array) + 1];
        strcpy(temp, array);
        return temp;
    }

    else
        return NULL;
}

int tString::getArrayValue()const
{
    int toUse = 0;
    int length = strlen(array);
    for(int i = 0; i < length; ++i)
        toUse += array[i];
    return toUse;
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
		delete [] array;
	if(!toAdd)
		return false;

	array = new char[strlen(toAdd) + 1];
	strcpy(array, toAdd);
	return true;
}

bool tString::add(const tString & toAdd)
{
	if(array)
		delete [] array;
	if(!toAdd.array);

	array = new char[strlen(toAdd.array) + 1];
	strcpy(array, toAdd.array);
	return true;

}


void tString::display()const
{
	using namespace std;
	if(array)
		cout<<array;

	return;
}

int tString::getFirstIndex()const
{
    int toUse = (int) array[0];

    if(toUse == 49)
        return 1;

    else if(toUse == 50)
        return 2;

    else if(toUse == 51)
        return 3;

    else
        return 0;

}

bool tString::copyToArg(char * toUse)const
{
    if(!array)
        return false;

    if(toUse)
        delete [] toUse;

    toUse = new char[strlen(array) + 1];
    strcpy(toUse, array);

    return true;
}

bool tString::copyToArg(tString & toUse)const
{
    return copyToArg(toUse.memId);
}
