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
	private:
		int consultNum;
		float weeklyFee;
};

#endif
