
//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)
#ifndef SERVICENODE_H
#define SERVICENODE_H
#include "../hierarchy/service.h"
#include "../model/person.h"
#include "../model/member.h"
#include "../model/provider.h"

struct serviceNode
{
    class person * aPerson;//to hold key to ensure proper data is fetched.
  class service * head;
  serviceNode * next;

};
#endif

#ifndef __SERVICE_LIST_H
#define __SERVICE_LIST_H
#include "../model/person.h"
#include "../model/member.h"
#include "../model/provider.h"
class serviceList
{
	public:
		serviceList();
		~serviceList();
		int getKey(const int toUse); //hashing function to get arr index
    int memberFunctions();//use this function as a wrapper for member only functions. Put those functions into the private section.
    int addPerson(const person & toAdd);
		bool addService(const service & toAdd);

private:
    void removeNodes(serviceNode *& toRemove);
    void removeServices(service *& toRemove);

    //int addPerson(const person & toAdd);

		//bool addService(const class service & toAdd);
		int getIndex(const int toUse);
		serviceNode ** table;
};

#endif
