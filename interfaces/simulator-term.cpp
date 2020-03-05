#include "simulator-term.h"

#include <iostream>

#include "../datacenter.h"
#include "util-term.h"


using namespace std;

int simulatorTerm() {
  int numChoices = 4;
  string choices[numChoices] = {"Run Friday at midnight mass reports", "Get acme updates",
                                "Quit", "Exit Program"};
  int (* dt[numChoices])() = {runFridayNightReports, getAcmeUpdates, 
                              returnExitValue, exitFunction};

  while(true) {
    int returnCode = menu("This terminal would not exist in the final product, however it is useful to show the operation of features that are not triggered via human input. ", choices, dt, numChoices);
    if(returnCode == EXITVALUE) {
      return 0;
    }
  }

  return 0;
}

int runFridayNightReports() {
  if(datacenter::instance()->generateFridayNightReports()) {  
    cout << "Reports generated successfully!" << endl;
  } else {
    cout << "Reports failed to generate. Try again later!" << endl;
  }
  return 0;
}

int getAcmeUpdates() {
  int numOfRecords = 2;
  acmeRecord* records = datacenter::instance()->generateFakeAcmeData(2);
  cout << "Generated fake acme records: " << endl;
  for(int i = 0; i < numOfRecords; ++i) {
    cout << "Member: " << records[i].id_num << " is " << (records[i].isSuspended ? "suspended" :  "not suspended") << endl;
  }
  if(datacenter::instance()->processAcmeRecords(records, 2)) {
    cout << "Successfully changed records in data center" << endl;
  } else {
    cout << "Failed to change records in data center, please try again!" << endl;
  }
  return 0;
}
