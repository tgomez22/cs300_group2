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
