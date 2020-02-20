#ifndef __DATACENTER_H
#define __DATACENTER_H

//CS300 Group #2
//
//Worked on by Tristan Gomez(Started: 2/5/2020)

#include "entityTable.h"
#include "serviceList.h"

class datacenter
{

	public:
		datacenter();
		~datacenter();
		int authenticateUser();
	private:
		int memberFunctions();
		int providerFunctions();
		int managerFunctions();

		int addMember();
		int addProvider();
    std::ostream generateUserReport(int userID);
    std::ostream generateFullReport(); //manager report function
		entityTable serviceTable; //membersorted
		entityTable providerTable;
		entityTable members; //provider sorted
};

#endif
