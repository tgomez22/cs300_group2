#ifndef __DATACENTER_H
#define __DATACENTER_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#include "entityTable.h"
#include "serviceList.h"

const int SIZE = 101; //size of the hash table. Use only prime numbers to help get a good dispersal in the hashing function.

const int MULTBY = 109; //multiply the key by this prime number to get a number much larger than the array(hash table). Then mod by size of the array to get index value. 
class datacenter
{

	public:
		datacenter();
		~datacenter();
		int authenticateUser();
	private:
		int memberFunctions();
		int providerFunctions();
		int serviceFunctions();

		bool addMember();
		bool addProvider();
		entityTable serviceTable; //membersorted
		entityTable providerTable;
		entityTable members; //provider sorted
};

#endif
