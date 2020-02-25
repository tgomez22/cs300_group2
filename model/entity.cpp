#include "entity.h"
#include "tString.h"
const int ID = 10;
const int SIZE = 101;
const int MULTBY = 97;
#include <cstring>
#include <iostream>
entity::entity()
{
}

entity::entity(const entity & toAdd)
{
	memId.add(toAdd.memId);
}

entity::~entity()
{

}


//FILE IO PEOPLE////////////////////////
bool entity::writeOut()
{
    //Insert here!
    //
    //
    //I think this function will help you. It returns a char *
    //to the data stored within memId. I was thinking that this would
    //be a good way to pull out the necessary data.
    //
    //char * toUse = memId.getString();




    //placeholder so it compiles
    return true;

}
///END FILE IO SECTION/////////////////
bool entity::addId(const entity & toAdd)
{
    memId.add(toAdd.memId);
}
//pass to terminal people. prompt for user id.
bool entity::addId()
{
	char temp[ID];
	using namespace std;
	cout<<"Please enter a new User Identification number: ";
	cin.get(temp, ID, '\n');
	cin.ignore(100, '\n');

	int length = strlen(temp);

	while(length != 9)
	{
		cout<<"User Identification number must be 9 digits long."<<endl;
		cout<<"Please enter a new User Identification number: ";
		cin.get(temp, ID, '\n');
		cin.ignore(100, '\n');

		length = strlen(temp);

	}

	return memId.add(temp);


}

int entity::compare(const entity & toCompare)const
{
    return memId.compare(toCompare.memId);
}

int entity::compare(char * toCompare)const
{
    return memId.compare(toCompare);
}

int entity::getIdValue()const
{
    return memId.getArrayValue();
}


bool entity::addId(const tString & toAdd)
{
	memId.add(toAdd);
}

bool entity::addId(char * toAdd)
{
	memId.add(toAdd);
}

void entity::display()const
{
	memId.display();
	return;
}

bool entity::isMatch(const entity & toSee)const
{
	return memId.compare(toSee.memId);
}

int entity::getFirstIndex()const
{
    return memId.getFirstIndex();
}
