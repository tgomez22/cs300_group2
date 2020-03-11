#include <iostream>
#include "../personList.h"
#include "../serviceList.h"
using namespace std;

void datacenterTest() {
	cout << "\n === COMMENCING TESTS === \n" << endl;
	cout << "\nPERSON LIST (AUTH):\n" << endl;
	personList ids;
	ids.displayStored();
	cout << "\nSERVICE LIST:\n" << endl;
	serviceList services;
	services.displayStored();
	cout << "\n ===== END OF TESTS ===== \n" << endl;
}

