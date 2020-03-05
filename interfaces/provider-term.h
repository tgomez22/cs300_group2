#ifndef __PROVIDER_TERM_H
#define __PROVIDER_TERM_H

#include <string>

using namespace std;

//Begin all provider terminal stuff here. When this function returns, the app will pop back up to the 'choose terminal' interface.
//Use exitFunction() to quit
int providerTerm(string id_num);

//initialize creating the service record, pass in provider id
int createServiceRecord(string id_num);

//after validation, create the service record
bool fillServiceRecord(string id_num, string providerId);

//run the provider report
int runProviderReport(string id_num);

//lets the provider open the directory
int useDirectory(string id_num);
//
#endif