//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#ifndef MEMBER_H
#define MEMBER_H

#include "person.h"
#include "entity.h"
class member: public person
{
	public:
		member();
		member(const member & toAdd);
		~member();
		void display()const;

       //FILE IO group!
        void writeOut();

        //Terminal group.
        bool readIn();

	private:
		bool suspended;
		float amtDue;
};

#endif
