#include "data_structures/serviceList.h"
#include "data_structures/personList.h"
#include <iostream>
bool again()
{
    using namespace std;
    int userResponse = 0;

    cout<<"Type 1 to go again."<<endl;
    cout<<"Type any other number to quit"<<endl;
    cout<<"Choice: ";
    cin>>userResponse;
    cin.ignore(100, '\n');

    if(userResponse == 1)
        return true;

    else
        return false;

}

int main()
{
 /*
    //I got it to compile and allow serviceList to exist as an object.
    //I have the add service and add person(provider or member) methods, and the destructor to test.
    //I'll make some sample tests to determine bugs or functionality issues (2/22 @ 4:13pm).
    serviceList users;
    using namespace std;
    do
    {

     }while(again());
  */

    // As of 2/21 @ 11pm this seems to work and return the correct authentication
    //values. We can abuse it to see what bugs manifest.
    //This tests personList.
    personList authentication;
    entity toUse;
    do
    {
        toUse.addId();
        authentication.add(toUse);
        int result = authentication.terminalAuthenticate(toUse);
        cout<<"Your Auth Value Was: "<<result<<"!"<<endl;
    }while(again());

    authentication.displayStored();
    return 0;
}
