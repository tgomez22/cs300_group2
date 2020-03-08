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
   
    bool checkValue = false;
    entity providerID;

    //pull ID out of string object.
    const char * temp = id.data();
    
    providerID.addId(temp);
    
    int result = authentication.authenticate(providerID);
    //2 indicates valid provider.
    if(result == 2)
        return true;

    else
       //return true;
       return false; //commenting out for now...the validation isn't working yet
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
bool datacenter::fillServiceRec(servRecInfo & myRec)
{
   char * p_name = new char(100);
   char * m_name = new char(100);
   service my_service_pro;
   service my_service_mem;
   
   provider numToFindPro;
   member numToFindMem;
   serviceNode copyPro;
   serviceNode copyMem;

   numToFindPro.addId(myRec.providerID);
   numToFindMem.addId(myRec.memID);
   
   dataStorage.getInfo(numToFindPro, copyPro);
   dataStorage.getInfo(numToFindMem, copyMem);

   //my_service_pro.getMemId(myRec.providerID);
   ///numToFindMem.getMemId(myRec.memID);

   numToFindPro.display();
   cout << endl;

  // p_name = numToFindPro.getName(); 
  // myRec.providerName.add(p_name);
  // m_name = numToFindMem.getName();
  // myRec.memberName.add(m_name);

   my_service_pro.addId(myRec.providerID);
   my_service_mem.addId(myRec.memID);

   my_service_pro.inputService(myRec);
   my_service_mem.inputService(myRec);

   dataStorage.addService(numToFindPro, my_service_pro);
   dataStorage.addService(numToFindMem, my_service_mem);
  
   my_service_pro.display();

   cout << "***************************************************\n";
   cout << "This is the information for this record: \n";
   cout << "***************************************************\n";
   cout << "Current Date & Time: ";
           my_service_pro.displayTime();
   cout << "Service Date: ";
           myRec.servDate.display();
   cout << endl;
   cout << "Provider Number: ";
           myRec.providerID.display();
   cout << endl;
   cout << "Provider Name: ";
           myRec.providerName.display();
   cout << endl;
   cout << "Member Number: ";
           myRec.memID.display();
   cout << endl;
   cout << "Member Name: ";
           myRec.memberName.display();
   cout << endl;
   cout << "Service Code: ";
           myRec.servCode.display();
   cout << endl;
   cout << "Service Description: ";
           myRec.servDescr.display();
   cout << endl;
   cout << "Comments: ";
           myRec.commentField.display();
   cout << endl;
   cout << "Service Fee: " << myRec.servFee << endl << endl;
   cout << "***************************************************\n";
   
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

bool datacenter::generateUserReport(string id, ofstream& email)
{
  return true;
}

bool datacenter::generateManagerReport(ofstream& email)
{
  return true;
}

