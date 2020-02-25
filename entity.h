//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)
#ifndef ENTITY_H
#define ENTITY_H
#include "tString.h"
class entity
{
	public:
        //default constructor, sets null values
		entity();

        //initializes to arg values
		entity(const entity & toAdd);
		~entity();
        
        //terminal people fctn. prompt user to directly enter their memId to store.
		bool addId();

        //copies arg into data member
		bool addId(const class tString & toAdd);
        bool addId(const entity & toAdd);
		bool addId(char * toAdd);


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

        //FILE IO PEOPLE!!! prototype to write out to file.
        bool writeOut();
	protected:
		tString memId;
};

#endif
