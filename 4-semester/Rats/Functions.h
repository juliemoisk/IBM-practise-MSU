#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Fraction.h"

using namespace std;

int nod (int m, int n)  //Euclidian algorithm
{
	m = abs(m);
	n = abs(n);
	while (m && n)
	{
		if (m < n) 
		{
			n %= m;
		}
		else
		{
			m %= n;
		}
	}
	return m + n;
}

//-----------------------------------------------------------------------------------------------------------------------------------
void Input (const string& filename, std::vector<CRat*>& vectors) 
{

	ifstream file(filename);
	
	CRatFactory* factories[] = { new CRat1Factory(), new CRat2Factory() };
	
	if (file.is_open()) 
	{
		string str;
		string name;
		int index; 

		Fraction f;

        	while (getline(file, str)) 
		{

			stringstream line(str);
			line >> index >> name;

			int count = index - 1;

			CRat *tmp = factories [index - 1] -> create(); 
			tmp -> Set_name(name);

			while (line >> index)
			{
				f.set_numerator(index);

				if (line >> index)
				{
		                        f.set_denominator(index);
					tmp -> push_back(f); 
				}

				else
				{
					index = 0;
					f.set_denominator(index);
					exit(0);
				}
				
			}
			vectors.push_back(tmp);	
		}

		file.close(); 
    	} 

	else 
	{
        	cout << "Error opening file: " << filename << endl;
		exit (0);
	}
}

void ConsoleView (std::vector<CRat*>& vectors)
{
	for (size_t i = 0; i < vectors.size(); i++)
     	{
		cout <<"\n Yours " << i + 1 << " group of fractions that is written in a ";
         	vectors[i] -> isBelong();

		vectors[i] -> Output(); 
     	}
}

void Separate (std::vector<CRat*>& vectors, std::vector<CRat1*>& vec1, std::vector<CRat2*>& vec2)
{
	for (CRat* r: vectors)
	{
		if (dynamic_cast<CRat1*>(r))
			vec1.push_back(dynamic_cast<CRat1*>(r));
		if (dynamic_cast<CRat2*>(r))
			vec2.push_back(dynamic_cast<CRat2*>(r));
	}
}

void Equal_quantity (std::vector<CRat*>& vectors)
{
	std::vector<CRat1*> vec1;
	std::vector<CRat2*> vec2;

	Separate (vectors, vec1, vec2);
	Equal (vec1);
	Equal (vec2);
}

void Equal (std::vector<CRat1*>& vectors)
{
	int length[vectors.size()];

	for (size_t i = 0; i< vectors.size(); i++)
	{
		length[i] = vectors[i] -> GetLength();
	}

	int max_length = length[0];

	for (size_t i = 0; i < vectors.size(); i++)
	{
		if (length[i] > max_length)
			max_length = length[i];
	}

	int difference[vectors.size()];

	for (size_t i = 0; i< vectors.size(); i++)
	{
		difference [i] = max_length - length[i];
	}

	Fraction f(0,1);

	for (size_t i = 0; i < vectors.size(); i++)
	{
		for (size_t k = 0; k < difference[i]; k++)
		{
			vectors[i] -> push_back(f);	
		}
	}	
}

void Equal (std::vector<CRat2*>& vectors)
{
	int length[vectors.size()];

	for (size_t i = 0; i< vectors.size(); i++)
	{
		length[i] = vectors[i] -> GetLength();
	}

	int max_length = length[0];

	for (size_t i = 0; i < vectors.size(); i++)
	{
		if (length[i] > max_length)
			max_length = length[i];
	}

	int difference[vectors.size()];

	for (size_t i = 0; i< vectors.size(); i++)
	{
		difference [i] = max_length - length[i];
	}

	Fraction f(0,1);

	for (size_t i = 0; i < vectors.size(); i++)
	{
		for (size_t k = 0; k < difference[i]; k++)
		{
			vectors[i] -> push_back(f);	
		}
	}	
}

void Functions (std::vector<CRat*>& vectors)
{
	CRatFactory* factories[] = {new CRat1Factory(), new CRat2Factory()};
	
	CRat* addition1 = factories[0] -> create();  
	CRat* addition2 = factories[1] -> create();

	CRat* substraction1 = factories[0] -> create();  
	CRat* substraction2 = factories[1] -> create();

	CRat* multiplication1 = factories[0] -> create();  
	CRat* multiplication2 = factories[1] -> create();

	int count1 = 0;
	int count2 = 0;

	for (CRat* r: vectors)
	{
		if (dynamic_cast<CRat1*> (r))
		{
			if (count1 == 0)
			{  
				*dynamic_cast<CRat1*>(addition1) = *dynamic_cast<CRat1*>(r);
				*dynamic_cast<CRat1*>(substraction1) = *dynamic_cast<CRat1*>(r);
				*dynamic_cast<CRat1*>(multiplication1) = *dynamic_cast<CRat1*>(r); 
			}

			else 
			{
				*dynamic_cast<CRat1*>(addition1) += *dynamic_cast<CRat1*>(r);
				*dynamic_cast<CRat1*>(substraction1) = *dynamic_cast<CRat1*>(substraction1) - *dynamic_cast<CRat1*>(r);
				*dynamic_cast<CRat1*>(multiplication1) = *dynamic_cast<CRat1*>(multiplication1) * *dynamic_cast<CRat1*>(r);
			}

			count1 ++;
		}
		if (dynamic_cast<CRat2*> (r))
		{
			if (count2 == 0)
			{ 
				*dynamic_cast<CRat2*>(addition2) = *dynamic_cast<CRat2*>(r);
				*dynamic_cast<CRat2*>(substraction2) = *dynamic_cast<CRat2*>(r);
				*dynamic_cast<CRat2*>(multiplication2) = *dynamic_cast<CRat2*>(r); 
			}

			else 
			{
				*dynamic_cast<CRat2*>(addition2) += *dynamic_cast<CRat2*>(r);
				*dynamic_cast<CRat2*>(substraction2) = *dynamic_cast<CRat2*>(substraction2) - *dynamic_cast<CRat2*>(r);
				*dynamic_cast<CRat2*>(multiplication2) = *dynamic_cast<CRat2*>(multiplication2) * *dynamic_cast<CRat2*>(r);
			}

			count2++;
		}
	}  

	cout << "\nThe result of addition between vectors of the 'line' group: " << "\n\t";   
	addition1 -> Output();

	cout << "\nThe result of addition between vectors of the 'column' group: " << "\n\t"; 
	addition2 -> Output();

	cout << "\nThe result of substraction between vectors of the 'line' group: " << "\n\t"; 
	substraction1 -> Output();

	cout << "\nThe result of substraction between vectors of the 'column' group: " << "\n\t"; 
	substraction2 -> Output();
	
	cout << "\nThe result of multiplication between vectors of the 'line' group: " << "\n\t"; 
	multiplication1 -> Output();

	cout << "\nThe result of multiplication between vectors of the 'column' group: " << "\n\t"; 
	multiplication2 -> Output();

	cout << "Please, enter two numbers of vectors from the 'line' group which the += operation will be performed on. ";

	cout << "Your options: ";

	int count = 0;
	
	for (CRat* r: vectors)
	{
		count++;

		if (dynamic_cast<CRat1*>(r))  cout << count << " ";
	}

	cout << "\n";

	int group[2];

	for (int i = 0; i < 2; i++)
	{
		int number;
		cin >> number;
		group[i] = number - 1;
	}

	*dynamic_cast<CRat1*>(vectors[group[0]]) += *dynamic_cast<CRat1*>(vectors[group[1]]);

	cout << "\nThe result of the += operation:" << "\n\t";
	vectors[group[0]] -> Output();	
}		
	
//-----------------------------------------------------------------------------------------------------------------------------------

void CRat:: Clean ()
{
	delete [] vector;
	SetZero();
}

void CRat:: SetZero ()
{
	vector = NULL;
	length = 0;
}

void CRat:: Copy (const CRat& tmp)
{
	if (this != &tmp)
	{
		memcpy (vector = new Fraction [length = tmp.length], tmp.vector, tmp.length * sizeof(Fraction));
	}
}

void CRat:: Set_name (string& name)
{
	this -> name = name;
}

int CRat:: GetLength () const
{
	return length;
}

Fraction& CRat:: operator [] (size_t i)
{
	return vector[i];
}

Fraction& CRat:: element (size_t i) const
{
	return vector[i];
}

void CRat:: push_back(const Fraction& tmp)
{
    Fraction* newVector = new Fraction[length + 1];

    for (int i = 0; i < length; i++)
    {
        newVector[i] = vector[i];
    }

    newVector[length] = tmp;
    delete[] vector;
    vector = newVector;
    length++;
}

//----------------------------------------------------------------------------------------------------------------------------------
const CRat1 CRat1:: operator + (const CRat1& tmp) const 
{	
	CRat1Factory sum1;
	CRat* sum = sum1.create_copy(*this); 
	for (int i = 0; i < tmp.GetLength(); i++)
		sum -> element(i) = sum -> element(i) + tmp.element(i);
	return *dynamic_cast<CRat1*>(sum);
}

const CRat1 CRat1:: operator - (const CRat1& tmp) const 
{
	CRat1Factory diff1;
	CRat* diff = diff1.create_copy(*this);
	for (int i = 0; i < tmp.GetLength(); i++)
		diff -> element(i) = diff -> element(i) - tmp.element(i);
	return *dynamic_cast<CRat1*>(diff);
}

const CRat1 CRat1:: operator * (const CRat1& tmp) const 
{	
	CRat1Factory product1;
	CRat* product = product1.create_copy(*this);
	for (int i = 0; i < tmp.GetLength(); i++)
		product -> element(i) = product -> element(i) * tmp.element(i);
	return *dynamic_cast<CRat1*>(product);
}

CRat1& CRat1::operator += (const CRat1& tmp)
{
	*this = *this + tmp;
	return *this;
}    
		
CRat1& CRat1:: operator = (const CRat1& tmp)  
{
	if (this != &tmp)
	{
		Clean ();
		Copy (tmp);
	}
	return *this;
}

//-----------------------------------------------------------------------------------------------------------------------------------

const CRat2 CRat2:: operator + (const CRat2& tmp) const 
{	
	CRat2Factory sum2;
	CRat* sum = sum2.create_copy(*this);
	for (int i = 0; i < tmp.GetLength(); i++)
		sum -> element(i) = sum -> element(i) + tmp.element(i);
	return *dynamic_cast<CRat2*>(sum);
}

const CRat2 CRat2:: operator - (const CRat2& tmp) const 
{
	CRat2Factory diff2;
	CRat* diff = diff2.create_copy(*this);
	for (int i = 0; i < tmp.GetLength(); i++)
		diff -> element(i) = diff -> element(i) - tmp.element(i);
	return *dynamic_cast<CRat2*>(diff);
}

const CRat2 CRat2:: operator * (const CRat2& tmp) const 
{	
	CRat2Factory product2;
	CRat* product = product2.create_copy(*this);
	for (int i = 0; i < tmp.GetLength(); i++)
		product -> element(i) = product -> element(i) * tmp.element(i);
	return *dynamic_cast<CRat2*>(product);
}

CRat2& CRat2::operator += (const CRat2& tmp)
{
	*this = *this + tmp;
	return *this;
}    
		
CRat2& CRat2:: operator = (const CRat2& tmp)  
{
	if (this != &tmp)
	{
		Clean ();
		Copy (tmp);
	}
	return *this;
}

//-----------------------------------------------------------------------------------------------------------------------------------

const Fraction Fraction:: operator + (const Fraction& tmp) const 
{
	int cnod;
	Fraction sum(*this);
	sum.numerator = sum.numerator * tmp.denominator + sum.denominator * tmp.numerator;
	sum.denominator *= tmp.denominator;
	cnod = nod(sum.numerator, sum.denominator);

	if (cnod != 0)
	{
		sum.numerator /= cnod;
		sum.denominator /= cnod;
	}

	return sum;
}

const Fraction Fraction:: operator - (const Fraction& tmp) const 
{
	int cnod;
	Fraction diff(*this);
	diff.numerator = diff.numerator * tmp.denominator - diff.denominator * tmp.numerator;
	diff.denominator *= tmp.denominator;
	cnod = nod(diff.numerator, diff.denominator);

	if (cnod != 0)
	{
		diff.numerator /= cnod;
		diff.denominator /= cnod;
	}

	return diff;
}

const Fraction Fraction:: operator * (const Fraction& tmp) const 
{
	int cnod;
	Fraction product(*this);
	product.numerator = product.numerator * tmp.numerator;
	product.denominator *= tmp.denominator;
	cnod = nod(product.numerator, product.denominator);

	if (cnod != 0)
	{
		product.numerator /= cnod;
		product.denominator /= cnod;
	}

	return product;
}

Fraction Fraction:: operator += (const Fraction& tmp)
{
	*this = *this + tmp;
	return *this;
}

void Fraction:: denom_check (const Fraction& tmp)
{
	if (tmp.denominator == 0)
	{
		cout << "ERROR ! Process can't be completed ! \nThe denominator of the fraction can't be equal to 0. Please, edit the input file. Each line must have an even number of elements" << endl;
	}
}

void Fraction:: set_numerator (int numerator)
{
	this -> numerator = numerator;
}

void Fraction:: set_denominator (int denominator)
{      
	this -> denominator = denominator;
	const Fraction& tmp = *this;
	denom_check (tmp);
}

bool Fraction:: is_zero () const
{
	if (this -> numerator == 0)
		return true;
	else
		return false;
}

//----------------------------------------------------------------------------------------------------------------------------------

ostream& operator << (ostream& cout, const Fraction& tmp)
{
	if (tmp.is_zero())
	{
		cout << "0";
	}

	else
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
				cout << tmp.numerator;
			else
				cout << "|" << tmp.denominator;
		}
	}	
	return cout;
}