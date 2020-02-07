//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)

#include <iostream>
#include "tString.h"
const int ID = 9;

class entity
{
	public:
		entity()
		~entity();
		bool addId();
		bool addId(const tString & ToAdd);
		bool addId(char * toAdd);
		void display()const;
		bool isMatch(const entity & toSee)const;
		bool isMatch(const class person & toSee)const;
	protected:
		tString memId;
};
