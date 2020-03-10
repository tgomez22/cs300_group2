#ifndef __MANAGER_TERM_H
#define __MANAGER_TERM_H

#include <string>

#include "../model/tString.h"

using namespace std;

//Begin all manager terminal stuff here. When this function returns, the app will pop back up to the 'choose terminal' interface.
//Use exitFunction() to quit
void managerTerm(string id_num);
int crudProvider(tString id_num);
int crudMember(tString id_num);
int doReports(tString id_num);

int deleteProvider(tString id_num);
int viewProvider(tString id_num);
int updateProvider(tString id_num);
int createProvider(tString id_num);

int deleteMember(tString id_num);
int viewMember(tString id_num);
int updateMember(tString id_num);
int createMember(tString id_num);

int doMemberReport(tString id_num);
int doProviderReport(tString id_num);
int doAccountsPayable(tString id_num);

#endif
