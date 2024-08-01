#pragma once
#include <iostream>
#include <string>
#include "CListNode.h"
using namespace std;

class CList
{
	private:
		CListNode *first, *curr, *last;
	public:
//-----------------------------------------------------------------------------------------------------------------------------------
		class Iterator
		{
			private:
				CListNode *curr;

			public:
				Iterator () 
				{
					curr = NULL;
				}
				
				Iterator (CListNode *curr)
				{
					this -> curr = curr;
				}
				
				bool operator != (const Iterator &tmp)
				{
					return curr != tmp.curr;
				}
				
				bool operator == (const Iterator &tmp)
				{
					return curr == tmp.curr;
				}

				CListNode* operator ++ ()
				{
					if (curr)
					{
						curr = curr -> next;
					}
					return curr;
				}  

				const char* operator * ()
				{
					return curr -> v;
				} 
		};
//-----------------------------------------------------------------------------------------------------------------------------------
		
		Iterator begin () 
		{
			return Iterator (first);
		}

		Iterator end ()
		{
			return Iterator (NULL);
		}

		CList ()
		{
			SetZero();
		}

		CList (const CList &tmp) 
		{
			SetZero ();
			Copy (tmp);
		}

		~CList ()
		{
			Clean();
		}

		CList& operator = (const CList &tmp) 
		{
			if (this != &tmp) 
			{
				Clean ();
				Copy(tmp);		
			}
			return *this;
		}

		bool Empty () const
		{
			return curr == NULL;
		}
		
		void Clean ()
		{
			Begin ();
			while (Delete_Current ());
			SetZero ();
		}

		void SetZero ()
		{
			first = NULL;
			curr = NULL;
			last = NULL;
		}

//-----------------------------------------------------------------------------------------------------------------------------------
		
		void Copy       (const CList &rhs); // (1)
		bool Next       ();                 // (2)
		bool Prev       ();                 // (3)
		void Add_After  (const char* tmp);  // (4)
		void Add_Before (const char* tmp);  // (5)
		void Position   (int pos);          // (6)

//-----------------------------------------------------------------------------------------------------------------------------------
		
		void Add_to_End      (const char* tmp );         // (1) add an element to the end
                void Add_List        (const CList &tmp);         // (2) all elements of the list to the end
                void Add_to_Position (const char* tmp, int pos); // (3) add to the given position

		void Begin           ();                         // (4) go to the beginning of the list
		void End             ();                         // (5) go to the end of the list

		CListNode* Next_Pointer ();                      // (6) get the pointer to the next element
		CListNode* Prev_Pointer ();                      // (7) get the pointer to the previous element
		CListNode* Curr_Pointer ();                      // (9) get the pointer to the current element
		
		int  Get_Position ();                            // (8) get the index of the current element

		bool Delete_Current  ();                         // (10) delete current element
		void Delete_Position (int pos);                  // (11) delete element with a certain index

		int Get_Length  ();                              // (12) the number of elements in the list
		void Delete_All ();                              // (13) delete all the elements of the list
		void Sort       ();                              // (14) sort by the given function

//-----------------------------------------------------------------------------------------------------------------------------------
	
		friend ostream& operator << (ostream &cout, CList &rhs)
		{      
			for (Iterator it = rhs.begin(); it != rhs.end(); ++it)
			{ 	
				cout << *it <<endl; 
			}

			return cout;
		}
	
		friend istream& operator >> (istream &cin, CList &rhs)
		{
			char str[512];
			const char* end = "end";
			int check = 1;
			int i = 0;
			while (check != 0)
			{
				if (i == 0)
				{
					cin.ignore(-1);
					cin.getline (str, 512);
				}
				
				if (i != 0)
				{
					cin.getline (str, 512); 
				}

				check = strcmp (str, end);

				if (check != 0)
				{
					rhs.Add_After(str); 
						
				}
				++i;
			}

			return cin;
		}
			
};












			














				







 	
				







			
		











