#ifndef __DATACENTER_H
#define __DATACENTER_H

#include <string>

#include "model/member.h"
#include "model/entity.h"

using namespace std;

//Provides an abstraction layer for access to the various lists and other things under tristan's purview
//Implements the singleton design pattern so it can hold the canonical version of all dataceneter data

struct acmeRecord {
  string id_num;
  bool isSuspended;
};

class datacenter {
  public:
    static datacenter* instance();
    //Is this ID associated with a provider?
    bool validateProvider(string id);
    //Is this ID associated with a manager?
    bool validateManager(string id);
    //Is this member ID valid?
    bool validateMember(string id);
    //Does basic text validation (isNumber and length == 9)
    bool checkIdFormat(string scannedId);
    //Run the friday night, mass report function. Returns true
    //If it was generated successfully.
    bool generateFridayNightReports();
    //Generate n fake records
    acmeRecord* generateFakeAcmeData(int n);
    //Send them into the datacenter
    bool processAcmeRecords(acmeRecord*, int);
    //Get a random ID from the datacenter
    string getRandomId();
  private:
    static datacenter *s_instance; 
    datacenter(); 
};

#endif