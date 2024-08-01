#include "CList.h"
#include <iostream>

// (1) ------------------------------------------------------------------------------------------------------------------------------

void CList::Add_to_End (const char* tmp) // add an element to the end
{
	CListNode* n = new CListNode ();
	n -> v = tmp;
	n -> prev = last;
	last -> next = n;
	last = n;
}

// (2) ------------------------------------------------------------------------------------------------------------------------------

void CList::Add_List (const CList &tmp) //all elements of the list to the end
{
	Copy (tmp);
}

// (3) ------------------------------------------------------------------------------------------------------------------------------

void CList::Add_to_Position (const char* tmp, int pos) // add to the given position 
{
	CListNode* rhs = curr;
	Position (pos);
	Add_Before (tmp);
	curr = rhs;
}

// (4) ------------------------------------------------------------------------------------------------------------------------------

void CList::Begin () // go to the beginning of the list
{
	curr = first;
}

// (5) ------------------------------------------------------------------------------------------------------------------------------

void CList::End ()  // go to the end of the list
{
	curr = last;
}

// (6) ------------------------------------------------------------------------------------------------------------------------------

CListNode* CList::Next_Pointer () //get the pointer of the next element
{
	return curr -> next;	
}

// (7) -----------------------------------------------------------------------------------------------------------------------------

CListNode* CList::Prev_Pointer () // get the pointer of the previous element
{
	return curr -> prev;
}

// (8) ------------------------------------------------------------------------------------------------------------------------------

int CList::Get_Position () //get the index of the current element
{
	Iterator it = first;
	int pos = 0;
	while (it != curr) 
	{
		++it;
		++pos;
	}
	return pos;
}

// (9) ------------------------------------------------------------------------------------------------------------------------------

CListNode* CList::Curr_Pointer () //get the pointer of the current element
{
	return curr;
}

// (10) -----------------------------------------------------------------------------------------------------------------------------

bool CList::Delete_Current () //delete the current element
{
	if (Empty()) return false;
	if (curr -> prev) curr -> prev -> next = curr -> next;
//	else last = curr -> next;
	else first = curr -> next;
	if (curr -> next) curr -> next -> prev = curr -> prev;
//	else first = curr -> prev;
	else last = curr -> prev;

	CListNode* r = curr;
	if (curr -> prev) curr = curr -> prev;
	else curr = curr -> next;
	delete r;
	return true;
}

// (11) -----------------------------------------------------------------------------------------------------------------------------

void CList::Delete_Position (int pos) //delete element with a certain index
{
	CListNode* tmp = curr;
	Position (pos);
	Delete_Current ();
	curr = tmp;
}

// (12) -----------------------------------------------------------------------------------------------------------------------------
		
int CList::Get_Length () // the number of elements in the list
{
	Iterator it = first; int length;
	for (length = 0; it != NULL; ++it)
	{
		length++;
	}
	return length;
}

// (13) -----------------------------------------------------------------------------------------------------------------------------
	 	
void CList::Delete_All () // delete all elements of the list
{
	int length = Get_Length ();
	for (int i = 0; i < length; i++)
	{
		Begin ();
		Delete_Current();
	}
}

// (14) -----------------------------------------------------------------------------------------------------------------------------		

void CList::Sort ()  //sort by the given function
{
	int length = Get_Length ();
	Begin ();
	for (int i = 0; i < length; i++)
	{
		CListNode* max = first;
		Begin();
		Next ();
		for (int j = 1; j < length - i; j++)
		{	
			if (*max < *curr) max = curr;
			Next ();
		}
		End ();
		for (int j = 0; j < i; j++)
		{
			Prev ();
		}
		const char *tmp = curr -> v;
		curr -> v = max -> v;
		max -> v = tmp;
	}
}
