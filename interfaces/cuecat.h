#ifndef __CUECAT_H
#define __CUECAT_H

#include <string>

using namespace std;

static char *getData(const char *input);  //For CueCat code to get data
static char *decode(char *in);            //For CueCat decodes the data

string getCueCat();        //For CueCat runs the other functions

#endif
