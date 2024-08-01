#include <iostream>
#include "CFunctions.cpp"
#include "HelpFunctions.cpp"

using namespace std;

int main (void) 
{

// Empty list and our own list

	cout << "We're creating an empty list."<< endl;
	CList TestList;
	if (TestList.Empty()) cout << "NULL " << endl;


	cout << "\nNow we're creating our own list:" << endl;
	CList List1;

	cout << "\t Please, enter your text. Remember that your last string has to be 'end', it indicates that you fininshed typing." << endl;

	cin >> List1;
	cout << "\nHere's your text:\n\n" << List1;

// Add an element to the end of the list

	cout << "\tPlease, enter the string that you want to add to the end of the list." << endl;

	char rhs[512];
	cin.ignore(-1);
	cin.getline (rhs, 512);

	List1.Add_to_End(rhs);

	cout << "\nHere's your altered text:\n\n" << List1 << endl;

// Add all the elements of the List2 to the end of the List1

	CList List2;

	cout << "\t Please, enter 2 your text. Remember that your last string has to be 'end', it indicates that you fininshed typing." << endl;

	cin >> List2;
	cout << "\nHere's your 2 text:\n\n" << List2 << endl;

	List1.Add_List(List2);
	cout << "\nHere's your combined text:\n\n" << List1 << endl;

// Add element to a certain position

	int position;
	cout << "\n\tPlease, enter the position that you want to add your element to." << endl;
	cin >> position;

	cout << "\tPlease, enter the string that you want to add to the " << position << " position." << endl;

	char tmp[512];
	cin.ignore();
	cin.getline (tmp, 512);

	List1.Add_to_Position(tmp, position);

	cout << "\nHere's your altered text:\n\n" << List1 << endl;

// The number of the elements in the list

	int length = List1.Get_Length();
	cout <<"\nLength = " << length << endl;
	
	cout << List1 << endl;

// Sort by the given function

	List1.Sort();

	cout << "\nHere's your sorted text:\n\n" << List1 << endl;

	cout << "\n Please, press ENTER to continue" << endl;
	cin.get();

// Go to the end of the list + delete current element

	CList list;

	const char* str[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
	
	for (int i = 0; i < 26; ++i)
	{
		list.Add_After(str[i]);
	}

	cout << list << endl;

	cout << "How do you want to change the element in the end ?" << endl;
	
	list.End();
	list.Delete_Current();

	char t[512];
	cin.ignore(-1);
	cin.getline (t, 512);

	list.Add_After(t);

// Go to the beginning of the list

	cout << "How do you want to change the element in the beginning ?" << endl;
	
	list.Begin();
	list.Delete_Current();

	char c[512];
	cin.ignore(-1);
	cin.getline (c, 512);

	list.Add_Before(c);

// Delete an element with a certain index

	cout << "What position do you want to change?" << endl;
	
	int pos;
	cin >> pos;

	cout << "How do you want to change it?" << endl;
	
	list.Delete_Position(pos);
	list.Position(pos);

	char m[512];
	cin.ignore();
	cin.getline (m, 512);

	list.Add_Before(m);

	cout << "\n" << list << endl;

// Get the pointer to the current, previous and next elements and their values

	cout << "\nYou want to know the previous and the next elements of the position #...?" << endl;
	int posit;
	cin >> posit;
	
	list.Position(posit);
	CListNode* current = list.Curr_Pointer();
	CListNode* previous = list.Prev_Pointer();
	CListNode* next = list.Next_Pointer();
	cout << "Current: " << *current << endl;
	cout << "Previous: " << *previous << endl;
	cout << "Next: " << *next << endl;

// Get the index of the current element

	int where = list.Get_Position();
	cout << "Your current position is " << where << endl;
	
// Delete all the elements of the list

	list.Delete_All();
	if (list.Empty()) cout << "The list was deleted\n" << endl; 

	return 0;
}





