#include "tString.h"
#include <cstring>
#include <iostream>
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

bool tString::addOverwrite(char * toAdd)
{
	if(array)
		delete [] array;
	if(!toAdd)
		return false;

	array = new char[strlen(toAdd) + 1];
	strcpy(array, toAdd);
	return true;
}

bool tString::addOverwrite(const tString & toAdd)
{
	if(array)
		delete [] array;
	if(!toAdd.array);

	array = new char[strlen(toAdd.array) + 1];
	strcpy(array, toAdd.array);
	return true;

}

bool tString::addNotOverwrite(char * toAdd)
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
bool tString::addNotOverwrite(const tString & toAdd)
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

void tString::display()const
{
	using namespace std;
	if(array)
		cout<<array;

	return;
}

int tString::getArrayValue()const
{
	if(!array)
		return 0;

	else
	{
		int length = strlen(array);
		int value = 0;

		for(int i = 0; i < length; ++i)
			value += array[i];	

		return value;
	}
}


void copyToArg(tString & destination)const
{
	if(destination.array)
		delete [] destination.array;

	destination.array = new char[strlen(array) + 1];
	strcpy(destination.array, array);

	return true;	
}

void copyFromArg(const tString & source)
{
	if(array)
		delete [] array;

	array = new char[strlen(source.array) + 1];
	strcpy(array, source);

	return;
}
