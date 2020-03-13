#include "manager-term.h"

#include <iostream>
#include <string>
#include <cstring>

#include "../datacenter.h"
#include "util-term.h"
#include "validation-term.h"

using namespace std;

void managerTerm(string id_num) {
  cout << "Entering Manager Terminal" << endl << endl;

  //CRUD
  //  Provider
  //  Member
  //Run Reports
  //  Select Report to run
  //Quit

   tString ID;

   char * id = new char[id_num.length() +1];
   strcpy(id, id_num.c_str());

   ID.add(id);

   int numChoices = 5;

   string choices[numChoices] = {"CRUD Provider", "CRUD Member", 
	                         "Run Reports", "Quit", "Exit Program"};

   int (* dt[numChoices])(tString) = {crudProvider, crudMember, doReports,
	                               returnExitValue2, exitFunction2};

   while(true) {
     int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, ID);
     if(returnCode == EXITVALUE) {
      return;
     }
   }
}

int crudProvider(tString id_num) {
  //Delete Provider
  //Read Provider
  //Create Provider
  //Update Provider
  
   int numChoices = 6;

   string choices[numChoices] = {"Delete Provider", "View Provider", 
	                         "Update Provider", "Create Provider",
                                 "Quit", "Exit Program"};

   int (* dt[numChoices])(tString) = {deleteProvider, viewProvider, updateProvider,
	                               createProvider, returnExitValue2, exitFunction2};

   while(true) {
     int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, id_num);
     if(returnCode == EXITVALUE) {
      return 0;
     }
   }

}

int deleteProvider(tString id_num) {
        
	cout << "delete a provider" << endl;
} 

int viewProvider(tString id_num) {
	cout << "view a provider" << endl;
}

int updateProvider(tString id_num) {
	cout << "update a provider" << endl;
}

int createProvider(tString id_num) {
       cout << "create a provider" << endl;
}

int crudMember(tString id_num) {

   int numChoices = 6;

   string choices[numChoices] = {"Delete Member", "View Member", 
	                         "Update Member", "Create Member",
                                 "Quit", "Exit Program"};

   int (* dt[numChoices])(tString) = {deleteMember, viewMember, updateMember,
	                               createMember, returnExitValue2, exitFunction2};



   while(true) {
     int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, id_num);
     if(returnCode == EXITVALUE) {
      return 0;
     }
   }
} 

int deleteMember(tString id_num) {
	cout << "delete a member" << endl;
} 

int viewMember(tString id_num) {
	cout << "view a member" << endl;
}

int updateMember(tString id_num) {
	cout << "update a member" << endl;
}

int createMember(tString id_num) {
       cout << "create a member" << endl;
}

int doReports(tString id_num) {
  //Member
  //Provider
  //Accounts Payable and ETF
   int numChoices = 5;

   string choices[numChoices] = {"Member Report", "Provider Report", 
	                         "Accounts Payable Report", "Quit", "Exit Program"};

   int (* dt[numChoices])(tString) = {doMemberReport, doProviderReport, doAccountsPayable,
	                               returnExitValue2, exitFunction2};


   while(true) {
     int returnCode = menu2("\nPlease choose from the following menu.", choices, dt, numChoices, id_num);
     if(returnCode == EXITVALUE) {
      return 0;
     }
   }
}


int doMemberReport(tString id_num) {
        string id;
        //Get ID number
	cout << "Please enter the ID you want to generate the report for:" << endl;
	id = getId();
        if(id.compare("") == 0) return 0;
        cout << "hereee,"<<endl;
        //Validate
        while(!datacenter::instance()->validateMember(id)) {
          cout << "The ID you entered is not associated with a valid member, please retry." << endl;
          id = getId();
          if(id.compare("") == 0) return 0;
	}
        //Run
	cout << "Running a member Report..." << endl;
        datacenter::instance()->runMemberReport(id);
}
int doProviderReport(tString id_num) {
	cout << "Run a provider report" << endl;
}
int doAccountsPayable(tString id_num) {
	cout << "Run an accounts Payable report" << endl;
}
