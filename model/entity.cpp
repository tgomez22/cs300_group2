#include "entity.h"
#include <cstring>
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

bool addId(const entity & toAdd);
{
    memId.add(toAdd.memId);
    return true;
}

bool entity::addId()
{
	char temp[ID];
	using namespace std;
	cout<<"Please enter a new User Identification number: ";
	cin.get(temp, ID, '\n');
	cin.ignore(100, '\n');

	int length = strlen(temp);

	while(length < 9 || length > 9)
	{
		cout<<"User Identification number must be 9 digits long."<<endl;
		cout<<"Please enter a new User Identification number: ";
		cin.get(temp, ID, '\n');
		cin.ignore(100, '\n');

		length = strlen(temp);
		
	}

	return memId.add(temp);

			
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

bool entity::isMatch(const class person & toSee)const
{
	return memId(toSee.memId);
}

int entity::getIdValue()const
{
	return memId.getArrayValue();
}

void entity::getMemId(tString & toUse)const
{
	memId.copyToArg(toUse);
	return;
}

void entity::getMemId(entity & toUse)const
{
	memId.copyToArg(toUse.memId);
	return;
}
		
int compare(const entity & toCompare)const
{
	return memId.compare(toCompare.memId);
}
int compare(char * toCompare)const
{
	return memId.compare(toCompare);
}
int compare(const tString & toCompare)const
{
	return memId.compare(toCompare);
}
