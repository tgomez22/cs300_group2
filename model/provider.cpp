#include "provider.h"
#include <iostream>

provider::provider():person()
{
}

provider::provider(const provider & toAdd):person(toAdd)
{
	consultNum = toAdd.consultNum;
	weeklyFee = toAdd.weeklyFee;
}

void provider::display()const
{
	using namespace std;
	person::display();
	cout<<"There were: "<<consultNum<<" consults this week."<<endl;
	cout<<"The fee owed to the provider this week is: $"<<weeklyFee<<endl;

	return;
}

bool provider::append()
{
//Mikayla do you want to build this interface or should I?
}
