#ifndef __PERSON_H
#define __PERSON_H
//CS300 Group #2
//
//Worked on by Tristan Gomez(started: 2/5/2020)

#include <string>

#include "../data_structures/serviceList.h"
#include "entity.h"


class person: public entity
{
	public:
		person();
		person(const person & toAdd);
		virtual ~person();

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
