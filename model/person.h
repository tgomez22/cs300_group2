//This is an abstract base class for the hierarchy. The derived objects will upcast to a 
//person * in order to fit in the same data structure. This flass contains virtual functions
//to be implemented in the derived classes. It also contains a showInfo function, which is 
//not virtual. This object contains tString objects representing a name, address, city, state, and zip code.

#ifndef __PERSON_H
#define __PERSON_H
//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)


//#include "../data_structures/serviceList.h"
#include "entity.h"

class person: public entity
{
	public:
		person();
		person(const person & toAdd);
		virtual ~person();

        virtual bool isSuspended()const = 0;

    //getter functions
    virtual char* getName() = 0;
    virtual char* getAddress() = 0;
    virtual char* getCity() = 0;
    virtual char* getState() = 0;
    virtual char* getZip() = 0;

	protected:
		tString name;
		//memNum exists in entity
		tString address;
		tString city;
		tString state;
	    tString zip;
		virtual void display()const = 0;

        //Shawn let me know if this prototype needs to change.
        virtual void writeOut() = 0;

        //For terminal folks! used in member and provider classes.
        virtual bool readIn() = 0;

        //Displays all private data, for terminal people.
        void showInfo()const;
};

#endif
