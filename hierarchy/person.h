//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include "entity.h"
class person: public entity
{
	public:
		person();
		person(const person & to_add);
		~person();
		virtual void display()const = 0;
		virtual bool append() = 0;

	protected:
		String name;
		//memNum exists in entity
		String address;
		String city;
		String state;
		String zip;
};
