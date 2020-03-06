#include <iostream>
#include "../personList.h"
using namespace std;

void datacenterTest() {
	cout << "commencing tests" << endl;
	personList table;
	table.readIn();
	table.displayStored();
}

