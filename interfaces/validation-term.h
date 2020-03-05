#ifndef __VALIDATION_TERM_H
#define __VALIDATION_TERM_H

#include <string>

using namespace std;

int scanId();
int typeId();            //Function to get one member ID by typing
void userTypeRouter(string memberId);

void chooseTerm();
int idThenProvider();
int idThenManager();
string getId();

#endif
