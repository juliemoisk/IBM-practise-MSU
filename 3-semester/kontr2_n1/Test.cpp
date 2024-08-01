#include <iostream>
#include "CFunctions.cpp"
using namespace std;

int CinLength () 
{
	int n;
	cout << "\n\tDefine the number of elements: ";
	cin >> n;
	return n;
}

int main (void) 
{
	try 
	{
		cout << "\nTest of the operators cin and cout:\n";

		int n;
		n = CinLength ();

		CComplexVector v1(n), v2(n);

		cout << "\n\tVector 1: "; cin >> v1; cout <<"\n\t\tVector 1 = " << v1;
		cout << "\n\tVector 2: "; cin >> v2; cout <<"\n\t\tVector 2 = " << v2;
	}
	catch (int error) 
	{
		cout << "\nError = " << error << endl;
	}  

	try 
	{
		cout << "\nTest of the copy constructor:"<< endl;

		int n;
		n = CinLength ();

		CComplexVector v1(n);
		cout << "\n\tVector 1: "; cin >> v1; cout << "\n\t\tVector 1 = " << v1;

		CComplexVector v2(v1);
		cout << "\n\t\tVector 2 = " << v2;
		
		complex <double> q;
		cout << "\n\tPlease, enter complex number q: ";
		cin >> q;

		int index;
		int index_rep;
		cout << "\n\tPLease, enter the index of the element that you want to change: "; cin >> index;
		if (index > n - 1) 
		{
			cout << "\n\tThe index is too big! Please, enter index that is not bigger than the length of the vector - 1: ";
			cin >> index_rep; 
			v1[index_rep] = q;
			cout << "\n\t\tVector 1 changed = "<< v1;
			cout << "\n\t\tVector 2 = " << v2;
		}
		else 
		{
		v1[index] = q;
		cout << "\n\t\tVector 1 changed = "<< v1;
		cout << "\n\t\tVector 2 = " << v2 << endl;
		}
	} 
	catch (int error) 
	{
		cout << "\nError = " << error << endl;
	}
	   

	try 
	{
		cout << "\nTest of +, -, +=, * operators:\n";

		int n;
		n = CinLength ();

		CComplexVector v1(n), v2(n), sum(n), dif(n);

		cout << "\n\tVector 1: "; cin >> v1; cout <<"\n\t\tVector 1 = " << v1;
		cout << "\n\tVector 2: "; cin >> v2; cout <<"\n\t\tVector 2 = " << v2;

		sum = v1 + v2;
		dif = v2 - v1;

		cout << "\n\tScalar product = " << v1 * v2 << endl;
		
		v1 += v2;

		cout << "\n\tSum = " << sum;
		cout << "\n\tDifference = " << dif;
		cout << "\n\tOperator += : " << v1 << endl;
	        
	}
	catch (int error) 
	{
		cout << "\nError = " << error << endl;
	}    

	try 
	{
		cout << "\nWhat if vectors have different length ? \n";

		int n1, n2;

		CComplexVector sum, dif;

		n1 = CinLength();
		CComplexVector v1(n1);
		cout << "\n\tVector 1: "; cin >> v1; cout <<"\n\t\tVector 1 = " << v1;

		n2 = CinLength();
		CComplexVector v2(n2);
		cout << "\n\tVector 2: "; cin >> v2; cout <<"\n\t\tVector 2 = " << v2;

		sum = v1 + v2;
		dif = v2 - v1;

		cout << "\n\tScalar product = " << v1 * v2 << endl;
		cout << "\n\tSum = " << sum;
		cout << "\n\tDifference = " << dif << endl;
	        
	}
	catch (int error) 
	{
		cout << "\nError = " << error << endl;
	}   
	     
	return 0;
} 
