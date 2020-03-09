#include "datacenter.h"

#include <string>
#include <cstring>
#include <functional>
#include <random>

#include "data_structures/personList.h"
#include "model/entity.h"

using namespace std;

datacenter* datacenter::s_instance = NULL;

//Taken from here: https://stackoverflow.com/a/43329456
bool randomBool() {
    static auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    return gen();
}

//Get the singleton
datacenter* datacenter::instance() {
  if(s_instance == NULL) {
    s_instance = new datacenter();
  }
  return s_instance;
}

bool datacenter::checkIdFormat(string scannedId) {
   int length = scannedId.length();
   bool checkValue = false;
  //from https://stackoverflow.com/a/4654718, in the comments
   bool isNumber = !scannedId.empty() && scannedId.find_first_not_of("0123456789") == std::string::npos;

   if(length != 9)
   {
      cout << "Sorry. User ID must be 9 digits long." << endl;
      cout << "Please try again." << endl;
      checkValue = false;
   }
   else if(!isNumber) 
   {
     cout << "Sorry, user id must be a number! (with 9 digits)." << endl;
     cout << "Please try again." << endl;
     checkValue = false;
   } 
   else
   {
      checkValue = true;
   }

   return checkValue;

}

//TODO with tristan
//
//I think this will be an empty constructor. Since the internal data are objects
//their constructors are implicitly called. Shawn's read in function should be
//called in the constructors of the data members. 
datacenter::datacenter() {

}

//TODO with tristan
//Is this ID allowed to access the provider terminal?
bool datacenter::validateProvider(string id) {
    
    //pull ID out of string object.
    const char * temp = id.data();
    

    //Package the char array into an entity object which is
    //compatible with the personList class.
    entity providerID;
    providerID.addId(temp);

    int result = authentication.authenticate(providerID);
    
    //2 indicates valid provider.
    if(result == 2)
        return true;

    else
       return true;
       //return false; commenting out for now...the validation isn't working yet
}

//TODO with tristan
//Is this ID allowed to access the manager terminal?
bool datacenter::validateManager(string id) {
    
    //pull ID out of string object
    const char * temp = id.data();
    

    //package the char array into an entity object which is
    //compatible with the personList class.
    entity managerID;
    managerID.addId(temp);

    int result = authentication.authenticate(managerID);
    
    //3 indicates valid manager.
    if(result == 3)
        return true;

    else
        return false;
}

//TODO with tristan
//Is this member ID valid?
bool datacenter::validateMember(string id)
{

    //pull ID out of string object.
    const char * temp = id.data();

    //package the char array into an entity object which is
    //compatible with the personList class.  
    entity memberID;
    memberID.addId(temp);

    int result = authentication.authenticate(memberID);

    //1 indicates valid member.
    if(result == 1)
        return true;

    else
        return true;
        //return false; commenting out for now...validation doesn't work
}

//TODO with tristan
//Gets a random ID from the datacenter for acme update generation
string datacenter::getRandomId() {
  return "123456789";
}

//TODO with tristan
//takes in service record data from terminal and copies to ???
bool datacenter::fillServiceRec(servRecInfo & servRec)
{
   //get memID, fill in for member
   
   //get provID, fill in for provider
   //

   return true;

}




//TODO with chris
//Run the mass report function
bool datacenter::generateFridayNightReports() {
  //will iterate through person list, running generateUserReport()
  //for every member, and generateManagerReport() once.
  return true;
}

acmeRecord* datacenter::generateFakeAcmeData(int num) {
  acmeRecord *records = new acmeRecord[num];
  for(int i = 0; i < num; ++i) {
    records[i].id_num = getRandomId();
    records[i].isSuspended = randomBool();
  }
  return records;
}

bool datacenter::processAcmeRecords(acmeRecord*, int num) {
  for(int i = 0; i < num; ++i) {
    //do something with each record
  }
  return true;
}

//----------------------------------------------------------
//report functions

bool datacenter::generateUserReport(string id, ostream& target = cout)
{
  //TODO: write user info printing

  //initialize list of services
  entity IdWrapper;
  IdWrapper.addId(id.data());
  serviceNode list;
  if(dataStorage.getInfo(IdWrapper, list)) {

    //iterate through list of services
    if(typeid(*(list.aPerson)) == typeid(member))
      generateMemberServiceReports(list, target);
    if(typeid(*(list.aPerson)) == typeid(provider))
      generateProviderServiceReports(list, target);

    return true;
  } else 
    return false;
}

bool datacenter::generateManagerReport(ostream& target = cout)
{
  return true;
}

bool datacenter::generateProviderServiceReports(serviceNode& list, ostream& target)
{
  //TODO: find way to get member ID + date received by computer,
  //      add up number of consultations and total fee,
  //      find something to do with service name and description
  while(list.head != NULL) { 
    char* member = list.head->getMemName();
    char* date = list.head->getDate();
    char* code = list.head->getServCode();
    char* description = list.head->getServDes();
    float fee = list.head->getServFee();

    target << "Service Date: " << date << endl;
    target << "\tDate Received by computer: " << " " << endl;
    target << "\tMember Provided to: " << member << endl;
    target << "\tMember code: " << " " << endl;
    target << "\tService Code: " << code << endl;
    target << "\tFee: " << fee << endl;

    delete member;
    delete date;
    delete code;
    delete description;

    list.head = list.head->toNext();
  }
  return true;
}

bool datacenter::generateMemberServiceReports(serviceNode& list, ostream& target)
{
  while(list.head != NULL) {
    char* provider = list.head->getProvName();
    char* service = list.head->getServName();
    char* date = list.head->getDate();

    target << "Service Date: " << date << endl;
    target << "\tProvider: " << provider << endl;
    target << "\tService: " << service << endl;

    delete provider;
    delete service;
    delete date;

    list.head = list.head->toNext();
  }
  return true;
}
