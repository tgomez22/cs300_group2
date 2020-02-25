#ifndef __ENTITY_TABLE_H
#define __ENTITY_TABLE_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#include "../model/entity.h"

class entityTable
{
	struct entityNode
	{
		entity * data;
		entityNode * next;
	
	};

	public:
		entityTable();
		~entityTable();

	private:
		entityNode ** table;
};

#endif
