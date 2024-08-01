#pragma once
#include <iostream>
#include <string.h>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;
                                                                                                                                   
class Fraction
{
	private:
		int numerator, denominator;
	public:
		Fraction (int numerator = 0, int denominator = 1)
		{
			this -> numerator   = numerator;
			this -> denominator = denominator;
		}
		
		const Fraction operator + (const Fraction& tmp) const;
		const Fraction operator - (const Fraction& tmp) const;
		const Fraction operator * (const Fraction& tmp) const;
		Fraction operator += (const Fraction& tmp);
		void set_numerator   (int numerator);
		void set_denominator (int denominator);
		void denom_check     (const Fraction& tmp);
		bool is_zero         () const;

	friend ostream& operator << (ostream& cout, const Fraction& tmp);
}; 

//-----------------------------------------------------------------------------------------------------------------------------------

class CRat1;
class CRat2;

//-----------------------------------------------------------------------------------------------------------------------------------
class CRat
{
	private:
		int length;
		Fraction *vector;
		string name;
		
	public:
            
	CRat ()
	{
		SetZero();
	}

	CRat (int n)
	{
		length = n;
		vector = new Fraction [length];
	}

	CRat (const CRat& rhs)
	{
		Copy (rhs);
	}

	virtual ~CRat ()
	{
		Clean ();
	}

	void Clean     ();
	void SetZero   ();
	void Copy      (const CRat& tmp    );
	void Set_name  (string& name       );
	void push_back (const Fraction& tmp);

	int  GetLength () const;

	Fraction& operator [] (size_t i);
	Fraction&  element    (size_t i) const;

	virtual void Output   () const = 0;
	virtual bool isBelong () const = 0;

	friend void Input          (const string& filename, std::vector<CRat*>& vectors);
	friend void ConsoleView    (std::vector<CRat*>& vectors);
	friend void Separate       (std::vector<CRat*>& vectors, std::vector<CRat1*>& vec1,std::vector<CRat2*>& vec2);
	friend void Equal_quantity (std::vector<CRat*>& vectors);
	friend void Equal          (std::vector<CRat1*>& vectors);
	friend void Equal          (std::vector<CRat2*>& vectors);
	
};

//-----------------------------------------------------------------------------------------------------------------------------------

class CRat1: public CRat
{
	string name;

	public:
		CRat1 ():                 CRat ()   {}
		CRat1 (int n):            CRat (n)  {}
		CRat1 (const CRat1& tmp): CRat(tmp) {}	

		~CRat1 () override
		{
			Clean ();
		}

		const CRat1 operator + (const CRat1& tmp) const; 
		const CRat1 operator - (const CRat1& tmp) const;
		const CRat1 operator * (const CRat1& tmp) const;
		CRat1& operator += (const CRat1& tmp);    		
		CRat1& operator = (const CRat1& tmp);  

		virtual void Output () const override
		{
			if (this -> GetLength() != 0)
			{
				cout << "\n\t" << "[";
				for (int i = 0; i < this -> GetLength() - 1; i++)
				{
					cout << this -> element(i) << ", ";
				}		
				cout << this -> element(this -> GetLength() - 1) << "]" << "\n" << endl;
			}
		}

		virtual bool isBelong () const override
		{
			cout << "line";
			return true;
		}								                
};

class CRat2: public CRat
{
	string name;

	public:
		CRat2 ():                 CRat ()   {}
		CRat2 (int n):            CRat (n)  {}
		CRat2 (const CRat2& tmp): CRat(tmp) {}	

		~CRat2 () override
		{
			Clean ();
		}

		const CRat2 operator + (const CRat2& tmp) const;
		const CRat2 operator - (const CRat2& tmp) const;
		const CRat2 operator * (const CRat2& tmp) const;
		CRat2& operator += (const CRat2& tmp);		
		CRat2& operator = (const CRat2& tmp);

		virtual void Output () const override
		{
			if (this -> GetLength() != 0)
			{
				cout << "\n\t" << "[";
				for (int i  = 0; i < this -> GetLength() - 1; i++)
				{
					cout << this -> element(i) << ", " << "\n\t ";
				}
				cout << this -> element(this -> GetLength() - 1) << "]" << "\n" << endl;
			}  
		}

		virtual bool isBelong () const override
		{
			cout << "column";
			return false;
		}			
};

class CRatFactory 
{
	public:
		virtual CRat* create() = 0;
		virtual CRat* create_copy (const CRat1& tmp) = 0;
		virtual CRat* create_copy (const CRat2& tmp) = 0;
};

class CRat1Factory : public CRatFactory 
{
	public:
		virtual CRat* create() override 
		{
			return new CRat1();
		}

		virtual CRat* create_copy (const CRat1& tmp) override
		{
			return new CRat1(tmp);
		}

		virtual CRat* create_copy (const CRat2& tmp) override
		{
			cout <<"ERROR!" << endl;
			exit(0);
		}	
};

class CRat2Factory : public CRatFactory 
{          
	public:
		virtual CRat* create() override
		{
			return new CRat2();
		}

		virtual CRat* create_copy (const CRat2& tmp) override
		{
			return new CRat2(tmp);
		}

		virtual CRat* create_copy (const CRat1& tmp) override
		{
			cout <<"ERROR!" << endl;
			exit(0);
		}
};  
