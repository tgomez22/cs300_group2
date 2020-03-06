//CS300 Group #2
//
//This is the implementation of the personList object prototypes. The personList object has an entity ** as its private data member. 

#include "personList.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

//const int ID = 10;
//const int SIZE = 101;
//const int MULTBY = 97;

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
	readIn(); //Populate the table with entity.txt data
}


//This function iterates through the entire hash table deallocating all dynamic memory.
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

//This functions assists the destructor in removing all dynamic memory.
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
//This function traverses the table and writes out each entity object to its
//appropriate text file
bool personList::writeOut()
{
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

//The function reads in from the entity text files and stores the memIds into
//the hash table. This function will be called in the contructor to populate
//data into the table upon program execution.
bool personList::readIn()
{
	ifstream myFile;
	myFile.open("data/entity.txt");
	entity anEntity;
	json toRead;
	while(!myFile.eof() && myFile >> toRead >> ws)
	{
		string temp = toRead["memId"];	
		const char * toUse = temp.c_str();
		anEntity.addId(toUse);
		add(anEntity);
	}
	myFile.close();
	return true;
}
////////////FILE IO END////////////////////////////FILE IO END///////////////////


//This function takes a constant entity object as an argument. It will copy the arguments data into 
//the hash table at an appropriate index.
bool personList::add(const entity & toAdd)
{
    using namespace std;

    int index = getIndex(toAdd.getIdValue());


    if(!table[index])
    {
        table[index] = new personNode;
        table[index]->anEntity.addId(toAdd);
        table[index]->next = NULL;

        //Used in testing.
        //cout<<"Successful Insert at Index: "<<index<<endl;

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

//This function returns an integer corresponding to a user's membership status.
//0 is returned if not found or doesn't exist.
//1 is returned if member. 2 is returned if provider. 3 is returned if manager.
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

//This is the hashing function for the hash table.
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


//This function helps with testing to display all currently stored information.
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
                temp->anEntity.display();
                cout<<endl;
                temp = temp->next;
            }

        }

    }

    return;
}
