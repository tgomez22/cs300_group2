//This is a derived class from class person. The class represents a provider of ChocAn and all of their associated information. 
//It implements the virtual functions from its immediate parent class. 

#ifndef __PROVIDER_H
#define __PROVIDER_H

//Tristan Gomez

#include "person.h"
#include "../interfaces/manager-term.h"

const int NAMESZ = 26;      //for the name & street address size
const int CITYSZ = 15;      //for the city name size
const int STATESZ = 3;      //for the state name size
const int ZIPSZ = 6;        //for the zip code size


class provider: public person
{
	public:
		provider();
		provider(const provider & toAdd);
		~provider();
		void display()const;

        //FIle IO
        void writeOut();

        //Terminal
        bool readIn();
        

        //This function always returns false in this object because providers 
        //cant be suspended. I did this so I wouldn't have to cast down to a 
        //member object.
        bool isSuspended()const;
        bool isSuspendedAndPrint()const;
    
    //getter functions
    char* getName();
    char* getAddress();
    char* getCity();
    char* getState();
    char* getZip();
    float getFee();
    int getConsultNum();
    
    //always returns false.
    bool suspendMember();
	
    void changeInfo(provider & my_provider);
    void changeInfo(userInfo & myInfo, float fee);
	//adds data to provider for use in serviceList	
	void addInfo(const char * addID, const char * addName, const char * addAddress, const char * addCity, const char * addState, const char * addZip, int addConsultNum, float addWeeklyFee);

	private:
		int consultNum;
		float weeklyFee;
};

#endif
