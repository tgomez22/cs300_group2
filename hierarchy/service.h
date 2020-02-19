//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)

#include "entity.h"

//This class is derived from the most base class, entity. It contains a member number that was inherited
//which allows the service to be tied to a member or provider. The service contains all specified information
//for a service, and a pointer to another service. 
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
