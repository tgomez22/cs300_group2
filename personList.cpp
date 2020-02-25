//CS300 Group #2
//
//Worked on by: Tristan Gomez(Started 2/10/2020)


#include "personList.h"
#include <iostream>
#include <cstring>

const int ID = 10;
const int SIZE = 101;
const int MULTBY = 97;

//Pointer arithmetic is used to initalize the array of personNode pointers as the private data member. 
//At the end of initialization, the pointer is set back to the first element. 
personList::personList()
{
	table = new personNode*[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		*table++ = NULL;
	}

	table -= SIZE;
}

personList::~personList()
{
    for(int i = 0; i < SIZE; ++i)
    {
        if(table[i])
            removeAll(table[i]);
    }
    
    delete [] table;
    table = NULL;

}

void personList::removeAll(personNode *& toRemove)
{
    if(!toRemove)
        return;

    removeAll(toRemove->next);

    delete toRemove;
    toRemove = NULL;

    return;

}


///////////FILE IO PEOPLE/////////////////////////////////FILE IO PEOPLE////////
//The traversal should be taken care of. Feel free to modify it as you please.
//As of now (2/22 @ 12:30pm), writeOut is an empty function. It can be edited in
//entity.cpp
bool personList::writeOut()
{
    //place holder return value. Feel free to change.
    if(!table) return false;

    for(int i = 0; i < SIZE; ++i)
    {
        if(table[i])
        {
            personNode * temp = table[i]; 
            while(temp)
            {
                temp->anEntity.writeOut();
                temp = temp->next;
            }
        }
    }
    
    return true;

}
////////////FILE IO END////////////////////////////FILE IO END///////////////////

bool personList::add(const entity & toAdd)
{
    /////////
    using namespace std;
    ////////////
    int index = getIndex(toAdd.getIdValue());
    

    if(!table[index])
    {
        table[index] = new personNode;
        table[index]->anEntity.addId(toAdd);
        table[index]->next = NULL;
        ////
        cout<<"Successful Insert at Index: "<<index<<endl;

        /////
        return true;
    }

    else
    {
        personNode * temp = table[index];

        while(temp && temp->anEntity.compare(toAdd) != 0)
        {
            temp = temp->next;
        }
        
        //doesnt exist in list so add
        if(!temp)
        {
            temp = table[index];
            table[index] = new personNode;
            table[index]->anEntity.addId(toAdd);
            table[index]->next = temp;
            return true;
        }
        
        //if Duplicate then dont add
        else
        {
            return false;
        }


    }
}


int personList::authenticate(const entity & toCheck)
{
    //check this fctn call
    int index = getIndex(toCheck.getIdValue());     

    if(!table[index])
        return 0;

    else
    {
        personNode * temp = table[index];
        
        //while still in chain and not found person
        while(temp && temp->anEntity.compare(toCheck) != 0)
        {
            temp = temp->next;
        }
        
        //place holder for person not found
        if(!temp)
            return 0;

        //person is found////////**************************
        else
        {
            return temp->anEntity.getFirstIndex();
        }
    }
}


//Terminal people, I've written in code to represent its intention and to make it testable.
//It assumes correct input. WILL 100% fail if you abuse it in any way.
int personList::terminalAuthenticate(const entity & toCheck)
{
    using namespace std;
    
    
    int index = getIndex(toCheck.getIdValue());     
    cout<<"AUTH INDEX IS: >>>>"<<index<<"!"<<endl;
    if(!table[index])
        return 0;

    else
    {
        personNode * temp = table[index];
        
        //while still in chain and not found person
        while(temp && temp->anEntity.compare(toCheck) != 0)
        {
            temp = temp->next;
        }
        
        //place holder for person not found
        if(!temp)
            return 0;

        //person is found////////**************************
        else
        {
            return temp->anEntity.getFirstIndex();
        }
    }
}


int personList::getIndex(int keyValue)
{
    int index = keyValue;
    index = index * MULTBY;
    
    index = index % SIZE;

    if(index < 0)
        index = -index;

    return index;
}

//terminal people
int personList::providerFunctions()
{
    return 0;
}
//terminal people
int personList::managerFunctions()
{
    return 0;
}

void personList::displayStored()const
{
    using namespace std;
    for(int i = 0; i < SIZE; ++i)
    {
        if(table[i])
        {
            cout<<"At index: "<< i <<endl;
            personNode * temp = table[i];
            while(temp)
            {
                cout<<"User Id: ";
                temp->anEntity.display();
                cout<<endl;
                temp = temp->next;
            }

        }

    }

    return;
}
