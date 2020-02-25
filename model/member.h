#ifndef __MEMBER_H
#define __MEMBER_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)


#include "person.h"
#include "entity.h"

class member: public person
{
	public:
		member();
		member(const member &other);
		~member();
		void display()const;

       //FILE IO group!
        void writeOut();

        //Terminal group.
        bool readIn();

	private:
		bool suspended;
};

#endif
