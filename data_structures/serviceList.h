#ifndef __SERVICE_LIST_H
#define __SERVICE_LIST_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)
#include "defs.h"
#include "../model/service.h"

//This is the linked list that members and providers will hold
//to keep a record of every service they have undergone.
//it's a linked list of services (or service keys), sorted
//by appointment date
class serviceList
{
	struct serviceNode
	{
		service *s;
		serviceNode *next;
		
	};


	public:
		serviceList();
		~serviceList();
		int getKey(const id_num); //hashing function to get arr index
		bool addService(const service&);
		int getIndex(const id_num);
	private:
	        void destroyService(serviceNode *&);
    		void deleteServices(serviceNode *&);
		serviceNode *list;
};

#endif
