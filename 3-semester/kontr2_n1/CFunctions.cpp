#include <iostream>
#include "CComplexVector.h"
using namespace std;

void CComplexVector:: Copy (const CComplexVector &v)
{
	if (this != &v) 
	{
		memcpy (arr = new complex <double> [length = v.length], v.arr, v.length * sizeof (complex <double>));
	}
} 

//-----------------------------------------------------------------------------------------------------------------------------------

CComplexVector & CComplexVector:: operator = (const CComplexVector &v) 
{
	if (this != &v) 
	{
		Clean();
		Copy(v);
	}
	return *this;
}

CComplexVector CComplexVector:: operator + (const CComplexVector &v) 
{
	CComplexVector tmp;
	if (length == v.length) 
	{
		tmp = CComplexVector(v.length);
		for (int i = 0; i < tmp.length; i++) 
		{
			tmp.arr[i] = v.arr[i] + arr[i];
		}
		return tmp;
	}
	else 
	{
		cout << "\nLengths of two given vectors are not equal !\n";
		throw -1;
	}
}

CComplexVector CComplexVector:: operator - (const CComplexVector &v) 
{
	CComplexVector rhs;
	if (length == v.length) 
	{
		rhs = CComplexVector(v.length);
		for (int i = 0; i < rhs.length; i++) 
		{
			rhs.arr[i] = arr[i] - v.arr[i];
		}
		return rhs;
	}
	else 
	{
		cout << "\nLengths of two given vectors are not equal !\n";
		throw -1;
	}	
}

complex <double> CComplexVector :: operator * (const CComplexVector &v) 
{
	complex <double> product = 0;
	if (length == v.length) 
	{
		for (int i = 0; i < v.length; i++) 
		{
			product += v.arr[i] * arr[i];
		}
		return product;
	}
	else 
	{
		cout << "\nLengths of two given vectors are not equal !\n";
		throw -1;
	}
}

complex <double>& CComplexVector:: operator [] (const int index) 
{
	return arr[index];
}

CComplexVector& operator += (CComplexVector &v, const CComplexVector &u) 
{
	if (v.length == u.length) 
	{
		for (int i = 0; i < v.length; i++) 
		{
			v.arr[i] += u.arr[i];
		}
		return v;
	}
	else 
	{
		cout << "\nLengths of two given vectors are not equal !\n";
		throw -1;
	}
}
/*int main (void) {
	cout << "Hi";
	return 0;
} */
