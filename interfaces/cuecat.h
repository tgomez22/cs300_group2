#ifndef __CUECAT_H
#define __CUECAT_H

#include "../model/entity.h"

static char *getData(const char *input);  //For CueCat code to get data
static char *decode(char *in);            //For CueCat decodes the data

bool getCueCat(entity & one_user);        //For CueCat runs the other functions

#endif
