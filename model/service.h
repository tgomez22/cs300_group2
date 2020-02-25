#ifndef __SERVICE_H
#define __SERVICE_H
//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)

#include <ctime>

#include "entity.h"

class service: public entity
{
	public:
		service();
		service(const service &other);
		~service();
		
	private:
		std::time_t dos; //date of service
		std::time_t currTime;
		std::string servName;
		std::string memName;
		//has memNum from base class entity
		id_num serviceCode;
		float serviceFee;
};

#endif 
