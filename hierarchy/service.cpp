//CS300 - Group 2 Project
//
//This is the implementation of the function declatations in the service.h file. 




#include <time.h>
#include <iostream>
#include "service.h" 
#include "../model/tString.h"
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

service::service()
{
  time_t numberTime;
  time(&numberTime); //This puts a number in numberTime of current time. (you don't have to enter the time of day. It automatically 
                      //tells you at allocation
  next = NULL;
  servFee = 0.0;

}

service::service(const service & toAdd)
{
  dos.add(toAdd.dos);
  numberTime = toAdd.numberTime;
  servName.add(toAdd.servName);
  memName.add(toAdd.memName);
  provName.add(toAdd.provName);
  servCode.add(toAdd.servCode);
  servDes.add(toAdd.servDes);
  servFee = toAdd.servFee;
  next = NULL;

}
bool service::inputService(servRecInfo & servRec)
{
      dos.add(servRec.servDate);
      servName.add(servRec.servDescr);
      memName.add(servRec.memberName);
      provName.add(servRec.providerName);
      servFee = servRec.servFee;
      servCode.add(servRec.servCode);
      servDes.add(servRec.commentField);
   
   return true;
}

void service::writeOut()
{

}

//read in function for terminal folks. I (TRISTAN) filled this in for testing
//feel free to change it. It assumes correct input at this time. needs "guards".
void service::addService()
{
    using namespace std;
    
    char userChoice;
    
    char dateOfService[INPUT];
    char memberName[INPUT];
    char providerName[INPUT];
    char serviceCode[INPUT];
    char serviceName[INPUT];
    char serviceDescription[SIZE];
    int feeDue = 0;
    
    cout<<"Please enter the date of service in mm/dd/yyyy: ";
    cin.get(dateOfService, INPUT, '\n');
    cin.ignore(100, '\n');
    dos.add(dateOfService);

    cout<<"What is the name of the member who received the service?: ";
    cin.get(memberName, INPUT, '\n');
    cin.ignore(100, '\n');
    memName.add(memberName);

    cout<<"Who provided the service?: ";
    cin.get(providerName, INPUT, '\n');
    cin.ignore(100, '\n');
    provName.add(providerName);

    cout<<"Would you like to see a directory of services? Y or N: ";
    cin>>userChoice;
    cin.ignore(100, '\n');

    if(userChoice == 'y' || userChoice == 'Y')
    {
        displayProviderDirectory();
    }
    
    cout<<"What is the numerical code of the service?: ";
    cin.get(serviceCode, INPUT, '\n');
    cin.ignore(100, '\n');
    servCode.add(serviceCode);

    cout<<"What is the name of the service being provided?: ";
    cin.get(serviceName, INPUT, '\n');
    cin.ignore(100, '\n');
    servName.add(serviceName);
    
    cout<<"What was the cost of the service?: ";
    cin>>feeDue;
    cin.ignore(100, '\n');

    servFee = feeDue;

    cout<<"Please enter a description of the service rendered: ";
    cin.get(serviceDescription, SIZE, '\n');
    cin.ignore(100, '\n');
    servDes.add(serviceDescription);

    return;

}

service::~service()
{

}

void service::display(void) const
{
  using namespace std;

  cout << "User ID: ";
  memId.display();
  cout << endl;

  cout << "Date of Service: ";
  dos.display();
  cout << endl;

  cout << "Service Name: ";
  servName.display() ;
  cout<< endl ;

  cout << "Member Name: ";
  memName.display();
  cout<< endl;

  cout<< "Provider Name: ";
  provName.display();
  cout<<endl;
  
  cout << "Service Code: ";
  servCode.display();
  cout<< endl;
  
  cout << "Service Fee: ";
  cout<< servFee << endl;

  cout<<"Service Comments: ";
  servDes.display();
  cout<< endl;
}

void service::displayTime(void)
{
  using namespace std;
  time(&numberTime);
  cout << ctime(&numberTime);

}

//ABBIE!!! I commented these out because curr_time doesnt
//seem to exist in this class as a data member. Maybe it got 
//deleted???
void service::convertDate(time_t & toConvert)
{
    
  //toConvert = curr_time;
  //time(&curr_time);
  
  //dos(ctime(&curr_time));

  return;
}

//ABBIE!!! table exists in service list. Most of this code should be moves there.
int service::getWeek()
{
    using namespace std;
  time_t timeToGet;
  time(&timeToGet);

  timeToGet -= 604800;

  cout << "This was a week ago: " << ctime(&timeToGet);
 


  //to find everything that was a week ago:
  //search through the table to find the service that matches the date
  /*
   *
  for(int i = 0; i < SIZE; ++i)
  {
    if(table[i])
    {
      service * current = new service;
      current = table[i]->head;
      while(current)
      {
        if(table[i]->head.numberTime >= timeToGet)
          //put this in the report function? For now we will just display???
          //reports peeps call your function here? Or something of that
          table[i]->head.display();
          current = current->next;
      }
    }
  }
  */
}

service *& service::toNext()
{
    return next;
}

//This function will display all the "stored providers" 
void service::displayProviderDirectory()const
{
	ifstream myFile;
	myFile.open("data/providerDirectory.txt");
	json service;
	while(!myFile.eof() && myFile >> service >> ws)
	{
		cout << "Service: " << service["servName"].get<string>() << " (" << service["servCode"] << ")" << endl;	
	}
	myFile.close();
	return;
}

//Pass in a service code and get back the description and fee
void service::getDescriptionFee(tString & servCode, tString & servName, float & servFee)
{
    ifstream myFile;
    myFile.open("data/providerDirectory.txt");
    json service;
    while(!myFile.eof() && myFile >> service >> ws) 
    {
		string tempServCode = service["servCode"];
		const char * toCompare = tempServCode.c_str(); 
		//if the service code passed in matches service in directory
		if(servCode.compare(toCompare) == 0)
		{
			//return service description (name)
			string tempServName = service["servName"];
			const char * addServName = tempServName.c_str();
			servName.add(addServName);
			//return service fee
			float addServFee = service["servFee"];
			servFee = addServFee;
			delete [] addServName;
		}
		delete [] toCompare;
    }   
    myFile.close();
    return;
} 

//getter functions
char* service::getMemName()
{
  return memName.getString();
}
char* service::getProvName()
{
  return provName.getString();
}
char* service::getServCode()
{
  return servCode.getString();
}
char* service::getServName()
{
  return servName.getString();
}
float service::getServFee()
{
  return servFee;
}
char* service::getDate()
{
  return dos.getString();
}

char* service::getServDes()
{
    return servDes.getString();
}
