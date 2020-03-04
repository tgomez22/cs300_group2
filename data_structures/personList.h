//CS300 Group #2
//INCLUDE CONST INT SIZE AND MULTBY
//This .h file needs to have a description of what the class is about
//
#ifndef PERSONNODE_H
#define PERSONNODE_H
#include "../model/entity.h"
#include "defs.h"
struct personNode
{
	entity anEntity;
	personNode * next;

};
#endif

#ifndef PERSONLIST_H
#define PERSONLIST_H
class personList
{
	public:
		personList();
		~personList();
		int authenticate(const entity & toCheck); //either pass in memID as arg, or prompt user to enter memID within function to return proper code.
        int terminalAuthenticate(const entity & toCheck);
		int managerFunctions(); //If manager, then call this function. Use it as a wrapper for functions that managers can use.
					//put those functions into the private section.
		int providerFunctions(); //If provider, then call this function. Use it as a wrapper for functions only providers can use.
                                //put those functions into the private section.
        void displayStored()const;

        bool add(const entity & toAdd);


	private:
        bool writeOut();
        int getIndex(int keyValue);
        void removeAll(personNode *& toRemove);
		personNode ** table;
};

#endif
