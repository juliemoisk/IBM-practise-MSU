#include "CList.h"
#include <iostream>

using namespace std;

// (1) ------------------------------------------------------------------------------------------------------------------------------

void CList::Copy (const CList &rhs)
{
	bool check = rhs.Empty();
	if (!check) 
	{
		for (Iterator it = rhs.first; it != NULL; ++it)
		{
			End ();
			Add_After (*it);
		}
		End();
	}
}

// (2) ------------------------------------------------------------------------------------------------------------------------------

bool CList::Next ()
{
	if (Empty()) return false;
	if (curr -> next == NULL) return false;
	else
	{
		curr = curr -> next; return true;
	}
}

// (3) ------------------------------------------------------------------------------------------------------------------------------

bool CList::Prev ()
{
	if (Empty()) return false;
	if (curr -> prev == NULL) return false;
	else
	{
		curr = curr -> prev; 
		return true;
	}
}

// (4) ------------------------------------------------------------------------------------------------------------------------------

void CList::Add_After (const char* tmp)
{
	if (curr == NULL)
	{
		CListNode* n = new CListNode();
		n -> v = new char [strlen(tmp) + 1];
		memcpy (const_cast <char*> (n -> v), tmp, strlen(tmp) + 1);
		curr = n;
		first = n;
		last = n;
	}	

	else 
	{
		CListNode *gig = curr;
		CListNode *n = new CListNode();
		n -> v = new char [strlen(tmp) + 1];
		memcpy (const_cast <char*> (n -> v), tmp, strlen(tmp) + 1);
		n -> next = gig -> next; 
		gig -> next = n;
		n -> prev = gig;
		if (n -> next) 
		{
			n -> next -> prev = n;
		}
		else last = curr = n; 
	}
}

// (5) ------------------------------------------------------------------------------------------------------------------------------

void CList::Add_Before (const char* tmp)
{
	if (curr == NULL)
	{
		CListNode* n = new CListNode();
		n -> v = new char [strlen(tmp) + 1];
		memcpy (const_cast <char*> (n -> v), tmp, strlen(tmp) + 1);
		curr = n;
		first = n;
		last = n;
	}
	
	else
	{
		CListNode *rhs = curr;
		CListNode *n = new CListNode();
		n -> v = new char [strlen(tmp) + 1];
		memcpy (const_cast <char*> (n -> v), tmp, strlen(tmp) + 1);
		n -> prev = rhs -> prev;
		rhs -> prev = n;
		n -> next = rhs;
		if (n -> prev) 
		{
			n -> prev -> next = n;
		}
		else first = curr = n;
	}	
}

// (6) ------------------------------------------------------------------------------------------------------------------------------

void CList::Position (int pos) 
{
	if (pos < 0 || pos > Get_Length()) throw -1;
	Begin();
	for (int i = 0; i < pos; i++) 
	{
		Next ();
	}
}

// (7) ------------------------------------------------------------------------------------------------------------------------------

/*bool CListNode::operator < (const CListNode &rhs) const
{
	int i ;
	for (i = 0; v[i] != '\0' && rhs.v[i] != '\0'; i++)
	{
		if (v[i] < rhs.v[i]) return true;
		if (v[i] > rhs.v[i]) return false;
	}
	if (v[i] != '\0') return false;
	return true;
}  */

bool CListNode::operator < (const CListNode &rhs) const
{

	int l1 = strlen(v);
	int l2 = strlen(rhs.v);
	if (l1 < l2) return true;
	if (l1 > l2) return false;

	return true;

}
	





