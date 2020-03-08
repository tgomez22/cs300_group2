
//CS300 Group #2
//
//This is the header file for the serviceList object. The serviceList object contains a serviceNode ** as its sole data member. The serviceNode
//object is defined above the serviceList one. The serviceNode contains a person *, in order to hold member or provider objects. A member or 
//provider object contains all relevant information for that person such as name, id number, address etc. It also contains a service * to hold
//a LLL implemented as a stack of services associated with that individual. It also contains a pointer to another serviceNode object.




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
#include "../hierarchy/service.h"
class serviceList
{
	public:
		serviceList();
		~serviceList();
		int getKey(const int toUse); //hashing function to get arr index
                int memberFunctions();//use this function as a wrapper for member only functions. Put those functions into the private section.
                int addPerson(const person & toAdd);
	        bool addService(const entity & toFind, const service & toAdd);

        //For Chris to use to pull individual member/provider profile and all services associated with that individual.
        bool getInfo(const entity & toFind, serviceNode & copy);

        bool copyServices(service *& dest, service * source)const;

        int isSuspended(const entity & toFind);
        
        //suspends a member's account.
        bool suspendMember(const entity & toFind);

private:
        void removeNodes(serviceNode *& toRemove);
        void removeServices(service *& toRemove);
        

        //int addPerson(const person & toAdd);

		//bool addService(const class service & toAdd);
		int getIndex(const int toUse);
		serviceNode ** table;
};

#endif
