#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <complex.h>
using namespace std;

class CComplexVector 
{
	int length;
	complex <double> *arr;

	public:
		CComplexVector (int n) 
		{
			length = n;
			arr = new complex <double> [length];
		}

		CComplexVector () 
		{
			SetZero();
		}
		
		CComplexVector (const CComplexVector &v) 
		{
			Copy (v);
		}
	
		~CComplexVector () 
		{
			Clean ();
		}

		CComplexVector& operator = (const CComplexVector &v);
		CComplexVector  operator - (const CComplexVector &v);
		CComplexVector  operator + (const CComplexVector &v);

		complex <double>  operator *  (const CComplexVector &v);
		complex <double>& operator [] (const int index); 

		friend CComplexVector& operator += (CComplexVector &v, const CComplexVector &u);

		void SetZero () 
		{
			arr = NULL;
			length = 0;
		}

		void Clean () 
		{
			delete [] arr;
			SetZero ();
		}

		int GetLength () 
		{
			return length;
		}  

		void Copy (const CComplexVector&v);

		friend int CinLength();

//-----------------------------------------------------------------------------------------------------------------------------------

friend ostream& operator << (ostream &cout, CComplexVector &v) 
{
	cout << "{ ";
	for (int i = 0; i < v.GetLength (); i++) 
		{
			if (i < v.GetLength () - 1) 
			{ 
				cout << v.arr[i] << ", ";
			}
			else 
			{
				cout << v.arr[i];
			}
		}
	cout << " }" << endl;
	return cout;
}	

friend istream& operator >> (istream &cin, CComplexVector &v) 
{
	for (int i = 0; i < v.GetLength(); i++) 
	{
		complex <double> p;
		cout << "\n\t\tEnter the element # " << i << " : ";
		cin >> p;
		v.arr[i] = p;
	}
	return cin;
}
};
