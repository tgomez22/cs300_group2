//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include "entity.h"
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
