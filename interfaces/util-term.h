#ifndef __UTIL_TERM_H
#define __UTIL_TERM_H

#include <string>

using namespace std;

const int EXITVALUE = 99;   //exit value to exit the program

int menu(string menuText, string* choices, int (* dispatchTable[])(), int numOfChoices);
int menu2(string menuText, string* choices, int (* dispatchTable[])(string), int numOfChoices, string id_num);
int exitFunction();
int exitFunction2(string id_num);
void cleanupCin();
int returnExitValue();
int returnExitValue2(string id_num);

#endif
