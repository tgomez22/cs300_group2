#include "member.h"
#include "entity.h"
#include "person.h"
#include <iostream>

member::member():person()
{
	suspended = false;
    amtDue = 0;
}

member::member(const member & toAdd):person(toAdd)
{
	suspended = toAdd.suspended;
	amtDue = toAdd.amtDue;
}

member::~member()
{

}

//Here's your prototype Shawn for writing out.
void member::writeOut()
{
}

//prototype for terminal group.
bool member::readIn()
{
    return true;
}

//fior terminal group. feel free to change.
void member::display()const
{
    using namespace std;
    if(suspended == true)
    {
        cout<<"Your account is suspended. "<<endl;
        cout<<"You owe: $"<<amtDue<<endl;
    }

    else
    {
        showInfo();
    }

    return;
}

bool member::isSuspended()const
{
    using namespace std;

    if(suspended == true)
    {
        display();
        return true;
    }

    else
        return false;
}
