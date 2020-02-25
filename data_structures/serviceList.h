#ifndef __SERVICE_LIST_H
#define __SERVICE_LIST_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)
#include "../model/service.h"
#include "../model/person.h"
#include "../model/member.h"
#include "../model/provider.h"

struct serviceNode
{
    person * aPerson;//to hold key to ensure proper data is fetched.
  service * head;
  serviceNode * next;

};

class serviceList
{
	public:
		serviceList();
		~serviceList();
		int getKey(const id_num); //hashing function to get arr index
		int getIndex(const id_num);
    int memberFunctions();//use this function as a wrapper for member only functions. Put those functions into the private section.
    int addPerson(const person & toAdd);
		bool addService(const service & toAdd);

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
