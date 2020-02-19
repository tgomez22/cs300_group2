//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include "entity.h"

//Class person is an abstract base class which will be used as a generic pointer type
//for its derived classes. This class contains all information that is associated with
//a person who works for/is a member of ChocAn. This base class contains virtual functions
//which will dynamically bind to the derived class functions.
class person: public entity
{
	public:
		person();
		person(const person & toAdd);
		virtual ~person();
		virtual void display()const = 0;
		virtual bool append() = 0;

	protected:
		tString name;
		//memNum exists in entity
		tString address;
		tString city;
		tString state;
		tString zip;
};
