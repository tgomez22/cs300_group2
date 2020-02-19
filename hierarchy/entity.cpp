#include "entity.h"
#include <cstring>

//default constructor, no data members to initalize.
entity::entity()
{

}

//copy constructor, allows the memId to be initalized to the 
//argument's data.
entity::entity(const entity & toAdd)
{
	memId.add(toAdd.memId);	
}

//default destructor, no data members to clear dynamic memory for, since
//data members manage it.
entity::~entity()
{

}

<<<<<<< Updated upstream
bool addId(const entity & toAdd);
{
    memId.add(toAdd.memId);
    return true;
}

=======
//prompts user to add an id number. Returns true if successfully added
//a valid length member id. returns false if can't add. 
>>>>>>> Stashed changes
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


//adds id, initalizes id value to the argument.
bool entity::addId(const tString & toAdd)
{
	memId.add(toAdd);
}

//adds id, initalizes id value to the argument.
bool entity::addId(char * toAdd)
{
	memId.add(toAdd);
}

//displays stored private data(member number)
void entity::display()const
{
	memId.display();
	return;
}

//checks if argument's data is the same as the calling object's data.
bool entity::isMatch(const entity & toSee)const
{
	return memId.compare(toSee.memId);
}
<<<<<<< Updated upstream

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
=======
>>>>>>> Stashed changes
