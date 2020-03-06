//This is the most base object within the class hierarchy. The sole data member is a
//tString object which holds a member ID number. This class is mostly used to authenticate users
//on startup and is the main stored information in the personList object.

#ifndef __ENTITY_H
#define __ENTITY_H
//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)

#include <iostream>
#include "tString.h"
#include "../data_structures/defs.h"

class entity
{
	public:
		entity();
		entity(const entity & toAdd); //Copy Constructor
		~entity();
		//int getId()const;
                void getMemId(tString & toUse)const;
                void getMemId(entity & toUse)const;

                char * isIDValid(char * compare);
                bool addIdFromTerm();
                bool checkIdFromScan(char *);

                //copies arg into data member
	        bool addId(const class tString & toAdd);
                bool addId(const entity & toAdd);
	        bool addId(char * toAdd);
            bool addId(const char * toAdd);

		void display()const;

                //returns true if matches arg.
		bool isMatch(const entity & toSee)const;

                //returns 1,2,3 depending on user type. if not value user, returns 0;
                int getFirstIndex()const;

                //returns sum of ascii values of stored data. Used in hashing fctn.
                int getIdValue()const;

                //strcmps arg against stored data. returns 0 if match
                int compare(const entity & toCompare)const;
                int compare(char * toCompare)const;
                int compare(const tString & toCompare)const;

                //returns true if text file is successfully opened and written to, otherwise returns false.
                bool writeOut();
	protected:
		 tString memId;
};

#endif
