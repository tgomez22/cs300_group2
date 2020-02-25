#include "service.h"
#include "tString.h"
#include <iostream>

const int MULTBY = 97;
const int ID = 10;
const int SIZE = 101;
service::service()
{
	next = NULL;
    serviceCode = 0;
    serviceFee = 0;
}

service::service(const service & toAdd)
{
	dos.add(toAdd.dos);
	currDate.add(toAdd.currDate);
	currTime.add(toAdd.currTime);
	servName.add(toAdd.servName);
	memName.add(toAdd.memName);
	serviceCode = toAdd.serviceCode;
	serviceFee = toAdd.serviceFee;
	next = NULL;
}

service::~service()
{
	next = NULL;
}

void service::display()const
{
	using namespace std;

	cout<<"Service: ";
    servName.display();
    cout<<endl;

	cout<<"Service code: "<<serviceCode<<endl;

	cout<<"Administered on: ";
    dos.display();
    cout<<endl;

	cout<<"Filed on: ";
    currDate.display();
    cout<<" at ";
    currTime.display();
    cout<<endl;

	cout<<"Member: ";
    memName.display();
    cout<<endl;
	cout<<"Member number: ";
    entity::display();
    cout<<endl;

	cout<<"Fee for service provided: $"<<serviceFee<<endl;

	return;
}

service *& service::toNext()
{
	return next;
}

//add this
bool service::addService()
{
    return true;
}
