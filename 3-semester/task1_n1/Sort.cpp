#include <iostream>
#include "CFunctions.cpp"
#include "HelpFunctions.cpp"

using namespace std;

int main (void) 
{
	CList List1;

	cout << "\t Please, enter your text. Remember that your last string has to be 'end', it indicates that you fininshed typing." << endl;

	cin >> List1;
	cout << "\nHere's your text:\n\n" << List1 << endl;

	List1.Sort();

	cout << "\nHere's your sorted text:\n\n" << List1 << endl;

	return 0;
}