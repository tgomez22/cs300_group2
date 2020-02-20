#ifndef __ENTITY_H
#define __ENTITY_H
//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)

#include <iostream>

using id_num = unsigned int;
const int ID = 9;

class entity
{
	public:
    	    entity();
	    entity(const entity & toAdd);
	    ~entity();
	    bool getIdFromTerm();
            bool checkIdFromScan(char * scanID);
	    void setId(id_num id);
	    int compare(const entity & toCompare)const;
	    id_num getIdValue()const;
	protected:
	    char* isIDValid(char*);
	    id_num id;
};

#endif
