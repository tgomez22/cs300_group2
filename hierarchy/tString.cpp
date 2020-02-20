#include "tString.h"
#include <cstring>
#include <iostream>

//initalizes the sole data member to null.
tString::tString()
{
	array = NULL;
}

//copy constructor, initalizes the data member to the value of the argument.
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

//copy constructor, initalizes the data member to the value of the argument.
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

//deallocates all dynamic memory and sets pointer to NULL.
tString::~tString()
{
	if(array)
		delete [] array;
	array = NULL;
}

//compares argument to value stored in object.
int tString::compare(char * toCompare)const
{
	return strcmp(array, toCompare);
}

//compares argument to value stored in object.
int tString::compare(const tString & toCompare)const
{
	return strcmp(array, toCompare.array);
}

//clears stored memory and initializes data member to argument's value.
//returns false if argument is empty.
//returns true if succssfully adding. 
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

//clears stores memory and initalizes data member to argument's value.
//returns false if argument is empty.
//returns true if succssfully adding. 
bool tString::addOverwrite(const tString & toAdd)
{
	if(array)
		delete [] array;
	if(!toAdd.array);

	array = new char[strlen(toAdd.array) + 1];
	strcpy(array, toAdd.array);
	return true;

}

//returns false if memory is stored. If calling object is empty, 
//then datat member is initalized to argument's value.
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

//returns false if memory is stored. If calling object is empty, 
//then datat member is initalized to argument's value.
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

//displays stored data in the object.
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
