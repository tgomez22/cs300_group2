//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)

#include "entity.h"

class service: public entity
{
	public:
		service();
		service(const service & to_add);
		~service();
		void display()const;
		bool appendService();
		service *& toNext();
		bool addService();

	private:
		String dos; //date of service
		String currDate;
		String currTime;
		String servName;
		String memName;
		//has memNum from base class entity
		String serviceCode;
		float serviceFee;
		service * next;
};
