#ifndef __UTIL_TERM_H
#define __UTIL_TERM_H

#include <string>
#include "../model/tString.h"
using namespace std;

const int EXITVALUE = 99;   //exit value to exit the program

int menu(string menuText, string* choices, int (* dispatchTable[])(), int numOfChoices);
int menu2(string menuText, string* choices, int (* dispatchTable[])(tString), int numOfChoices, tString id_num);
int exitFunction();
int exitFunction2(tString id_num);
void cleanupCin();
int returnExitValue();
int returnExitValue2(tString id_num);

#endif
