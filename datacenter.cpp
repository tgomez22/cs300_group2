#include "datacenter.h"

#include <string>
#include <cstring>

#include "data_structures/personList.h"

using namespace std;

datacenter* datacenter::s_instance = NULL;

datacenter* datacenter::instance() {
  if(s_instance == NULL) {
    s_instance = new datacenter();
  }
  return s_instance;
}

//todo with tristan
datacenter::datacenter() {

}

bool datacenter::checkIdFormat(string scannedId) {
   int length = scannedId.length();
   bool checkValue = false;
  //from https://stackoverflow.com/a/4654718, in the comments
   bool isNumber = !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;

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
bool datacenter::validateProvider(string id) {
  return true;
}

//todo with tristan
bool datacenter::validateManager(string id) {
  return true;
}


	
