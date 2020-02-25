//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)
#ifndef PERSON_H
#define PERSON_H
#include "entity.h"
#include "tString.h"
class person: public entity
{
	public:
		person();
		person(const person & toAdd);
		virtual ~person();
		virtual void display()const = 0;

        //Shawn let me know if this prototype needs to change.
        virtual void writeOut() = 0;
        
        //For terminal folks! used in member and provider classes.
        virtual bool readIn() = 0;
        
        //Displays all private data, for terminal people. 
        void showInfo()const;

	protected:
		tString name;
		//memNum exists in entity
		tString address;
		tString city;
		tString state;
		tString zip;
};

#endif
