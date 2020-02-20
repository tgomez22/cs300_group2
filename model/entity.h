#ifndef __ENTITY_H
#define __ENTITY_H
//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)

#include <iostream>
#include "tString.h"

using id_num = unsigned int;
const int ID = 9;

class entity
{
	public:
		entity();
		entity(const entity & other); //Copy Constructor
		~entity();
		setId();
		bool isMatch(const entity & other)const;
		int getId()const;
		int compare(const entity & toCompare)const;
	protected:
		 id_num memId;
};

#endif
