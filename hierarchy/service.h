//CS300 group #2
//
//Worked on by Tristan Gomez(started:2/5/2020)
#ifndef SERVICE_H
#define SERVICE_H

#include "../model/entity.h"
#include <time.h>

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
		service *& toNext();

        //a read in function for terminal group. Implemented by Tristan for testing, feel free to alter as you like.
		void addService();


        void convertDate(time_t & toConvert); //use this function to turn the date into a string. 
                                        //very easy implementation. tells you the current date
        void displayTime(void); //this will display the time in a readable form.
        int getWeek();
	    void displayProviderDirectory()const;	
	private:
		tString dos; //date of service in form: www mmm dd hh:mm:ss yyyy
        long numberTime; //number of seconds since jan 1st 1970 00:00:00 (good for week calculations
		tString servName;
		tString memName;//MEMBER NAME!!!
        tString provName;//PROVIDER NAME!
		//has memNum from base class entity
		tString servCode;
		float servFee;
		service * next;
};

#endif
