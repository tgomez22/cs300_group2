//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)
#ifndef SERVICE_H
#define SERVICE_H
#include "entity.h"
class service: public entity
{
    public:
		service();
		service(const service & toAdd);
		~service();
		void display()const;
		service *& toNext();
		bool addService();

	private:
		tString dos; //date of service change to struct time
	    tString currDate; //change to struct time
		tString currTime; //change to struct time
		tString servName;
		tString memName;
		//has memNum from base class entity
		int serviceCode;
		float serviceFee;
		service * next;
};

#endif
