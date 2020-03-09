#ifndef __PROVIDER_TERM_H
#define __PROVIDER_TERM_H

#include <string>
#include "../model/tString.h"
using namespace std;

struct servRecInfo{

   tString currentDateTime;
   tString providerID;
   tString providerName;
   tString memID;
   tString memberName;
   tString servDate;
   tString servCode;
   tString servDescr;
   float servFee = 0.0;
   tString commentField;

};

//Begin all provider terminal stuff here. When this function returns, the app will pop back up to the 'choose terminal' interface.
//Use exitFunction() to quit
int providerTerm(string id_num);

//initialize creating the service record, pass in provider id
int createServiceRecord(tString id_num);

//after validation, create the service record
bool fillServiceRecord(tString mem_id_num, tString id_num);

//run the provider report
int runProviderReport(tString id_num);

//lets the provider open the directory
int useDirectory(tString id_num);
//
#endif
