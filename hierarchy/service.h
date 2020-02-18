//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)

#include "entity.h"

class service: public entity
{
	public:
		service();
		service(const service & toAdd);
		~service();
		void display()const;
		bool appendService();
		service *& toNext();
		bool addService();
		
	private:
		tString dos; //date of service
		tString currDate;
		tString currTime;
		tString servName;
		tString memName;
		//has memNum from base class entity
		tString serviceCode;
		float serviceFee;
		service * next;
};
