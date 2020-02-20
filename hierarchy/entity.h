//CS300 group #2
//
//Worked on by Tristan Gomez (Started 2/5/2020)

#include <iostream>
#include "tString.h"
const int ID = 9;

//Entity is the base class which the rest of the class hierarchy is built off of.
//It contains a sole protected data member which is of type tString. It represents a 
//user's member Id number. 
class entity
{
  public:
    entity();
    entity(const entity & toAdd);
    ~entity();
    bool addId();
    bool addId(const entity & toAdd);
    bool addId(const tString & toAdd);
    bool addId(char * toAdd);
    void display()const;
    bool isMatch(const entity & toSee)const;
    char* isIDValid(char*);
    <<<<<<< Updated upstream
      bool isMatch(const class person & toSee)const;
    int getIdValue()const;
    void getMemId(tString & toUse)const;
    void getMemId(entity & toUse)const;
    int compare(const entity & toCompare)const;
    int compare(char * toCompare)const;
    int compare(const tString & toCompare)const;
    =======
      >>>>>>> Stashed changes
  protected:
      tString memId;
};
