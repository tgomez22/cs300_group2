//CS300 - Group 2 Project
//This file is the implementation of the serviceList object prototypes. 

#include "serviceList.h"
#include "../hierarchy/service.h"
#include "../model/entity.h"
#include "../model/person.h"
#include "../model/provider.h"
#include "../model/member.h"
#include "defs.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;
//const int ID = 10;
//const int SIZE = 101;
//const int MULTBY = 97;


//Constructor for the serviceList.
serviceList::serviceList()
{
	table = new serviceNode*[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
	readIn();
}


//destructor iterates through and deallocates all dynamic memory.
serviceList::~serviceList()
{
    for(int i = 0; i < SIZE; ++i)
    {
        if(table[i])
        {
            removeNodes(table[i]);
        }
    }

    delete [] table;
    table = NULL;
}



//This function assists the destructor in deallocating all dynamic memory.
void serviceList::removeNodes(serviceNode *& toRemove)
{
    if(!toRemove)
        return;

    removeNodes(toRemove->next);
    
    if(toRemove->aPerson)
        delete toRemove->aPerson;

    toRemove->aPerson = NULL;
    removeServices(toRemove->head);
    toRemove->head = NULL;

    return;

}

//This function assists the destructor in deallocating all dynamic memory.
void serviceList::removeServices(service *& toRemove)
{
    if(!toRemove)
        return;

    removeServices(toRemove->toNext());
    delete toRemove;
    toRemove = NULL;

    return;

}

int serviceList::memberFunctions()
{
    return 0;
}


//This function takes a constant reference to a person object, which is an
//abstract base class. Member or provider objects will be passed in as arguments
//to fill the hash table.
int serviceList::addPerson(const person & toAdd)
{

    int index = getKey(toAdd.getIdValue());

    if(!table[index])
    {
        table[index] = new serviceNode;

        const member * ptr = dynamic_cast<const member*>(&toAdd);
        if(ptr)
        {
            table[index]->aPerson = new member(*ptr);
            table[index]->head = NULL;
            table[index]->next = NULL;
            return 1;
        }

        else
        {
            const provider * ptr2 = dynamic_cast<const provider*>(&toAdd);
            if(ptr2)
            {
                table[index]->aPerson = new provider(*ptr2);
                table[index]->head = NULL;
                table[index]->next = NULL;
                return 1;
            }

            return 0;
        }


    }

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toAdd) != 0)
        {
            temp = temp->next;
        }

        //fell off the list so no duplicate. add at head.
        if(!temp)
        {
            temp = table[index];

            table[index] = new serviceNode;

            const member * ptr3 = dynamic_cast<const member*>(&toAdd);
            if(ptr3)
            {
                table[index]->aPerson = new member(*ptr3);
                table[index]->head = NULL;
                table[index]->next = temp;
                return 1;
             }

            else
            {
                const provider * ptr4 = dynamic_cast<const provider*>(&toAdd);
                if(ptr4)
                {
                    table[index]->aPerson = new provider(*ptr4);
                    table[index]->head = NULL;
                    table[index]->next = temp;
                    return 1;
                }

                return 0;

            }
        }

        //duplicate found so return failure.

    }

}

int serviceList::getKey(const int toUse)
{
	int key = toUse * MULTBY;
	key = key % SIZE;

    if(key < 0)
        key = -key;

	return key;
}

bool serviceList::addService(const entity & toFind, const class service & toAdd)
{
	int index = getKey(toFind.getIdValue());

    //no person to associate service with
	if(!table[index])
	{
		return false;
	}

	else
	{
		serviceNode * temp = table[index];

		while(temp && temp->aPerson->compare(toFind)!= 0)
		{
			temp = temp->next;
		}

        //fell off list, member doesn't exist
		if(!temp)
		{
			//must be an existing member to add a service.
			return false;
		}


        //found member, adding service
		else
		{
			service * headHolder = temp->head;
			temp->head = new service(toAdd);
			temp->head->toNext() = headHolder;
			return true;

		}
	}

}


//Search and pull records function for chris.
//I can change the prototype to accept a char * or tString object to search for.
//Pass in a blank/empty serviceNode to be copied into.
//returns false if no person doesn't exist, returns true if successful copy.
bool serviceList::getInfo(const entity & toFind, serviceNode & copy)
{
    int index = getKey(toFind.getIdValue());
    
    //no member/provider exists.
    if(!table[index])
        return false;

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toFind))
        {
            temp = temp->next;
        }
        
        //pointer fell off list, no match exists.
        if(!temp)
            return false;
        
        //person found.
        else
        {
            //casting to find out if provider or member.
            const member * ptr = dynamic_cast<const member*>(*&temp->aPerson); 
            if(ptr)
            {
                copy.aPerson = new member(*ptr);
                copy.next = NULL;
                copyServices(copy.head, temp->head);
            }

            else
            {
                const provider * ptr2 = dynamic_cast<const provider*>(*&temp->aPerson);
                if(ptr2)
                {
                    copy.aPerson = new provider(*ptr2);
                    copy.next = NULL;
                    copyServices(copy.head, temp->head);
                }
            }


        }

        return true;
    }
}

//copies LLL of services.
bool serviceList::copyServices(service *& dest, service * source)const
{
    if(!source)
        return false;
    
    dest = new service(*source);
    dest->toNext() = NULL;

    copyServices(dest->toNext(), source->toNext());

    return true;
}

//returns 1 if member is suspended and couts their balance due. 
//returns 0 if member is active.
//returns 2 if member doesn't exist.
int serviceList::isSuspended(const entity & toFind)
{
    int index = getKey(toFind.getIdValue()); 

    if(!table[index])
        return 2;

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toFind))
        {
            temp = temp->next;
        }

        //pointer fell off the list, no match exists.
        if(!temp)
            return 2;
        
        //person found
        else
        {
           bool suspend = temp->aPerson->isSuspended();
           if(suspend == false)
               return 0;
           else
               return 1;
        }
    }


}

bool serviceList::suspendMember(const entity & toFind)
{
    int index = getKey(toFind.getIdValue());

    if(!table[index])
        return false;

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toFind))
        {
            temp = temp->next;
        }

        //pointer fell off list, no match exists.
        if(!temp)
            return false;
        
        //person found.
        else
        {
            return temp->aPerson->suspendMember();
        }

    }
}

void serviceList::readIn()
{
	//read from member text file and populate
	ifstream memberFile;
    memberFile.open("data/member.txt");
    member aMember;
    json mRead;
    while(!memberFile.eof() && memberFile >> mRead >> ws) 
    {   
        string tempID = mRead["memId"]; //json serialization library only compatible with string class
		string tempName = mRead["name"];
		string tempAddress = mRead["address"];
		string tempCity = mRead["city"];
		string tempState = mRead["state"];
		string tempZip = mRead["zip"];
		bool addSuspended = mRead["suspended"];
		float addAmtDue = mRead["amtDue"];
        const char * addID = tempID.c_str();
		const char * addName = tempName.c_str();
		const char * addAddress = tempAddress.c_str();
		const char * addCity = tempCity.c_str();
		const char * addState = tempState.c_str();
		const char * addZip = tempZip.c_str();
        aMember.addInfo(addID, addName, addAddress, addCity, addState, addZip, addSuspended, addAmtDue);
        addPerson(aMember);
    }   
    memberFile.close();
	//read from provider text file and populate
	ifstream providerFile;
    providerFile.open("data/provider.txt");
    provider aProvider;
    json pRead;
    while(!providerFile.eof() && providerFile >> pRead >> ws) 
    {   
	    string tempID = pRead["memId"]; //json serialization library only compatible with string class
        string tempName = pRead["name"];
        string tempAddress = pRead["address"];
        string tempCity = pRead["city"];
        string tempState = pRead["state"];
        string tempZip = pRead["zip"];
        int addConsultNum = pRead["consultNum"];
        float addWeeklyFee = pRead["weeklyFee"];
        const char * addID = tempID.c_str();
        const char * addName = tempName.c_str();
        const char * addAddress = tempAddress.c_str();
        const char * addCity = tempCity.c_str();
        const char * addState = tempState.c_str();
        const char * addZip = tempZip.c_str();
        aProvider.addInfo(addID, addName, addAddress, addCity, addState, addZip, addConsultNum, addWeeklyFee);
        addPerson(aProvider);
    }   
    providerFile.close();
    return;
}

void serviceList::readInServices()
{
    ifstream serviceFile;
    serviceFile.open("data/service.txt");
	entity anEntity;
    service aService;
    json toRead;
    while(!serviceFile.eof() && serviceFile >> toRead >> ws) 
    {   
		string tempDOS = toRead["DOS"];
        string tempMemId = toRead["memId"]; //json serialization library only compatible with string class
        string tempMemName = toRead["memName"];
        string tempProvName = toRead["provName"];
        string tempServCode = toRead["servCode"];
        string tempServDes = toRead["servDes"];
        string tempServName = toRead["servName"];
        float addServFee = toRead["servFee"];
        const char * addDOS = tempDOS.c_str();
        const char * addMemId = tempMemId.c_str();
        const char * addMemName = tempMemName.c_str();
        const char * addProvName = tempProvName.c_str();
        const char * addServCode = tempServCode.c_str();
        const char * addServDes = tempServDes.c_str();
		const char * addServName = tempServName.c_str();
        aService.addInfo(addDOS, addMemId, addMemName, addProvName, addServCode, addServDes, addServName, addServFee);
		anEntity.addId(addMemId);
        addService(anEntity, aService);
    }   
    serviceFile.close();
    return;
}

void serviceList::displayStored()const
{
    using namespace std;
    for(int i = 0; i < SIZE; ++i)
    {   
        if(table[i])
        {   
            cout<<"At index: "<< i <<endl;
            serviceNode * temp = table[i];
            while(temp)
            {   
                temp->aPerson->display();
				service * ptr = temp->head;
				while(ptr)
				{
					ptr->display();
					ptr = ptr->toNext();	
				}
                cout<<endl;
                temp = temp->next;
            }   
        }   
    }   
    return;
}

bool serviceList::displayInfo(const entity & toFind)
{
    int index = getKey(toFind.getIdValue());

    if(!table[index])
        return false;

    else
    {
        serviceNode * temp = table[index];
        
        //search for person and stop traversing when compare == 0
        while(temp && temp->aPerson->compare(toFind) != 0)
        {
            temp = temp->next;
        }

        if(!temp)
            return false;

        else
        {
            temp->aPerson->display();
            service * ptr = temp->head;

            while(ptr)
            {
                ptr->display();
                ptr = ptr->toNext();
            }

            return true;
        }



    }
}

bool serviceList::removeMember(const entity & toRemove)
{
    int index = getKey(toRemove.getIdValue());

    if(!table[index])
        return false;

    else
    {
        return removeMember(table[index], toRemove);
    }
}

bool serviceList::removeMember(serviceNode *& ptr, const entity & toRemove)
{
    bool result = false;

    if(!ptr)
        return result;

    result = removeMember(ptr->next, toRemove);

    if(ptr->aPerson->compare(toRemove)==0)
    {
        removeServices(ptr->head);

        if(ptr->aPerson)
            delete ptr->aPerson;

        ptr->aPerson = NULL;

        serviceNode * temp = ptr->next;
        delete ptr;
        ptr = temp;

        return true;
    }
}

bool serviceList::updateMemberInfo(const entity & toFind)
{
    int index = getKey(toFind.getIdValue());

    if(!table[index])
        return false;

    else
    {
        serviceNode * temp = table[index];

        while(temp && temp->aPerson->compare(toFind) != 0)
        {
            temp = temp->next;
        }
        
        if(!temp)
            return false;

        else
        {
            temp->aPerson->readIn();
            return true;
        }
    }
}
