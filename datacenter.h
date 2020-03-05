#ifndef __DATACENTER_H
#define __DATACENTER_H

#include <string>

#include "model/member.h"
#include "model/entity.h"

using namespace std;

//Provides an abstraction layer for access to the various lists and other things under tristan's purview
//Implements the singleton design pattern so it can hold the canonical version of all dataceneter data

class datacenter {
  public:
    static datacenter* instance();
    bool validateProvider(string id);
    bool validateManager(string id);
    bool checkIdFormat(string scannedId);
  private:
    static datacenter *s_instance; 
    datacenter(); 
};

#endif
