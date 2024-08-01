#include <iostream>
#include <stdlib.h>
#include "Fraction.h"
#include "Functions.h"

using namespace std;

int main (void)
{	
	
	std::vector <CRat*> vectors;
	
	cout << "Please, enter the name of the file that contains data: ";
	string name;
	cin >> name;

	Input (name, vectors);

	ConsoleView    (vectors);
	Equal_quantity (vectors);
	Functions      (vectors);
	return 0;
}