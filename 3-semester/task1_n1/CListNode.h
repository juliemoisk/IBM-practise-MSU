#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class CListNode 
{
	private:
		void Clean () 
		{
			delete [] v; 
			SetZero();
		}
		void SetZero ()
		{
			prev = NULL;
			next = NULL;
			v = NULL;
		}

	public:
		const char* v;
		CListNode *prev, *next;

		CListNode () 
		{
			SetZero();
		}

		CListNode (const char* rhs) 
		{
			v = new char[strlen(rhs) + 1];
			memcpy (const_cast <char*> (v), rhs, strlen(rhs) + 1);
			prev = NULL;
			next = NULL;
		}

		~CListNode () 
		{
			Clean ();
		}
	
		bool operator < (const CListNode &rhs)const;

		const char* operator * ()
		{
			return v;
		}
	
		friend ostream& operator << (ostream &cout, CListNode &tmp)
		{
			cout << *tmp;
			return cout;
		}	
};