#ifndef __ENTITY_TABLE_H
#define __ENTITY_TABLE_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#include "defs.h"
#include "../model/entity.h"

class entityTable
{
	struct entityNode
	{
		entity *ent;
		int authority; //1 for member, 2 provider, 3 manager
		entityNode * next;
	
	};

	public:
		entityTable();
		~entityTable();

 		int authenticate(const entity & toCheck); //either pass in memID as arg, or prompt user to enter memID within function to return proper code. 
		int managerFunctions(); //If manager, then call this function. Use it as a wrapper for functions that managers can use.
    		//put those functions into the private section. 	
    		int providerFunctions(); //If provider, then call this function. Use it as a wrapper for functions only providers can use. 
   		 //put those functions into the private section. 
  	private:
    		bool add(const entity & toAdd);
    		int getIndex(int keyValue);
    		void destroyEntity(entityNode *&);
        entity* getEntity(int keyValue); //returns entity (do we need this and get index?)
    		entityNode ** table;
};

#endif
