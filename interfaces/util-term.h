#ifndef __UTIL_TERM_H
#define __UTIL_TERM_H

#include <string>

using namespace std;

const int EXITVALUE = 99;   //exit value to exit the program

int menu(string menuText, string* choices, int (* dispatchTable[])(), int numOfChoices);
int exitFunction();
void cleanupCin();
int returnExitValue();

#endif
