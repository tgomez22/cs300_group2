//CS300 group #2
//
//This is the header file for the service object. This object represents everything needed for a service report to ChocAn. It has
//date of service, name of service, name of member, name of provider, cost of service, code of service, and a pointer to another
//service. This object is associated with the member who received the service, as well as, the provider who game the service.



#ifndef SERVICE_H
#define SERVICE_H

#include "../interfaces/provider-term.h"
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

                bool inputService(servRecInfo & servRec);
		//Write out to text file
       	void writeOut(); 
		//a read in function for terminal group. Implemented by Tristan for testing, feel free to alter as you like.
		void addService();


                void convertDate(time_t & toConvert); //use this function to turn the date into a string. 
                                        //very easy implementation. tells you the current date
                void displayTime(void); //this will display the time in a readable form.
		char* getTime(void);     //this will return the time in a readable form.
                int getWeek();
		void displayProviderDirectory()const;	
		void getDescription(tString & servCode, tString & servName);
		      
      //getter functions
      char* getMemName();
      char* getProvName();
      char* getServCode();
      char* getServName();
      float getServFee();
      char* getDate();
      char* getServDes();
      char* getEntryTime();
		//Add service data to object for use in serviceList
		void addInfo(const char * addDOS, const char * addMemId, const char * addMemName, const char * addProvName, const char * addServCode, const char * addServDes, const char * addServName, float servFee);
	private:
		tString dos; //date of service in form: www mmm dd hh:mm:ss yyyy
		long numberTime; //number of seconds since jan 1st 1970 00:00:00 (good for week calculations
    time_t entryTime; // time service was generated
		tString servName;
		tString memName;//MEMBER NAME!!!
		tString provName;//PROVIDER NAME!
		tString servDes; //service description.
		//has memNum from base class entity
		tString servCode;
		float servFee;
		service * next;
};

#endif
