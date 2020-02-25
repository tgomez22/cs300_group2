//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)
#ifndef SERVICENODE_H
#define SERVICENODE_H
#include "service.h"
#include "person.h"
#include "member.h"
#include "provider.h"

struct serviceNode
{
    person * aPerson;//to hold key to ensure proper data is fetched.
	service * head;
	serviceNode * next;

};

#endif

#ifndef SERVICELIST_H
#define SERVICELIST_H
#include "person.h"
#include "member.h"
#include "provider.h"
class serviceList
{
	public:
		serviceList();
		~serviceList();
		int memberFunctions();//use this function as a wrapper for member only functions. Put those functions into the private section.

        int addPerson(const person & toAdd);
		bool addService(const class service & toAdd);
	private:
        void removeNodes(serviceNode *& toRemove);
        void removeServices(service *& toRemove);

        //int addPerson(const person & toAdd);
		int getKey(const int toUse); //hashing function to get arr index

		//bool addService(const class service & toAdd);
		int getIndex(const int toUse);
		serviceNode ** table;
};

#endif
