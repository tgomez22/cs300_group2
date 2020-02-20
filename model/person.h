#ifndef __PERSON_H
#define __PERSON_H
//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include <string>
#include <list>

#include "../data_structures/serviceList.h"
#include "entity.h"


class person: public entity
{
	public:
		person();
		person(const person & toAdd);
		~person();

    virtual std::list<service> getServiceList() = 0; //used by report generation functions. Only returns copy of protected data.

	protected:
		std::string name;
		//memNum exists in entity
		std::string address;
		std::string city;
		std::string state;
		std::string zip;
		serviceList services;
};

#endif
