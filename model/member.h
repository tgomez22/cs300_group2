//This object is derived from the person abstract base class. This class implements
//virtual functions of its parent class. This object is used to store all necessary 
//information for a member of ChocAn.

#ifndef __MEMBER_H
#define __MEMBER_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)


#include "person.h"
#include "entity.h"

const int NAMESZ = 26;      //for the name & street address size
const int CITYSZ = 15;      //for the city name size
const int STATESZ = 3;      //for the state name size
const int ZIPSZ = 6;        //for the zip code size

class member: public person
{
	public:
		member();
		member(const member &other);
		~member();
		void display()const;

        //asks if member is suspended.
        bool isSuspended()const;
        
        //actually suspends the member.
        bool suspendMember();

       //FILE IO group!
        void writeOut();

        //Terminal group.
        bool readIn();

    //getter functions
    char* getName();
    char* getAddress();
    char* getCity();
    char* getState();
    char* getZip();
    float getFee();

	private:
		bool suspended;
        float amtDue;
};

#endif
