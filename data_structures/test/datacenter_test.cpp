#include <iostream>
#include "../personList.h"
using namespace std;

void datacenterTest() {
	cout << "\n === COMMENCING TESTS === \n" << endl;
	personList table;
	table.readIn();
	table.displayStored();
	cout << "\n ===== END OF TESTS ===== \n" << endl;
}

