#include "member.h"
#include "entity.h"
#include "person.h"
#include <iostream>
member::member():person()
{
	suspended = false;
    amtDue = 0.0;
}

member::member(const member & toAdd):person(toAdd)
{
	suspended = toAdd.suspended;
	amtDue = toAdd.amtDue;
}

member::~member()
{
}

//Here's your prototyppe Shawn for writing out.
void member::writeOut()
{

}

//Prototype for terminal group
bool member::readIn()
{
}

void member::display()const
{
    using namespace std;
    if(suspended)
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
