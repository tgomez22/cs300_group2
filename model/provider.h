#ifndef __PROVIDER_H
#define __PROVIDER_H

//Tristan Gomez

#include "person.h"

class provider: public person
{
	public:
		provider();
		provider(const provider & toAdd);
		~provider();
		void display()const;

        //FIle IO
        void writeOut();

        //Terminal
        bool readIn();
        

        //This function always returns false in this object because providers 
        //cant be suspended. I did this so I wouldn't have to cast down to a 
        //member object.
        bool isSuspended()const;
	private:
		int consultNum;
		float weeklyFee;
};

#endif
