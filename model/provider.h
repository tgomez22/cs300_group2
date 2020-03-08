//This is a derived class from class person. The class represents a provider of ChocAn and all of their associated information. 
//It implements the virtual functions from its immediate parent class. 

#ifndef __PROVIDER_H
#define __PROVIDER_H

//Tristan Gomez

#include "person.h"

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
    
    //getter functions
    char* getName();
    char* getAddress();
    char* getCity();
    char* getState();
    char* getZip();
    float getFee();
    
    //always returns false.
    bool suspendMember();
	
	//adds data to provider for use in serviceList	
	void addInfo(char * addID, char * addName, char * addAddress, char * addCity, char * addState, char * addZip, int addConsultNum, float addWeeklyFee);
	private:
		int consultNum;
		float weeklyFee;
};

#endif
