//CS300 Group #2
//
//This is the header file for the personList object. The personList contains a personNode ** as its private data member. The personNode is defined
//above the personList object. The personNode contains an entity object, containing a user's member number. The personNode also contains a pointer
//to another object of the same type.
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
		//bool readIn(); uncomment if running tests

	private:
        bool writeOut();
		bool readIn();
        int getIndex(int keyValue);
        void removeAll(personNode *& toRemove);
		personNode ** table;
};

#endif
