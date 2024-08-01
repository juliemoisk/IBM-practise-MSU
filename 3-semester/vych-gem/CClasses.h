#pragma once
#include <iostream>
#include <cmath>
#include <cstring>
#define dimension 2
using namespace std;

class CDot 
{
	private:
		int x, y;
	public:
		CDot ()
		{
			SetZero();
		}
		
		CDot (int u, int v)
		{
			x = u;
			y = v;
		}
		
		void SetZero ()
		{
			x = 0;
			y = 0;
		}

		void SetDot (int u,  int v)
		{
			x = u;
			y = v;
		}

		int Get_x ()
		{
			return x;
		}
		
		int Get_y ()
		{
			return y;
		}

		void ShowDot ();
	
		CDot& operator = (const CDot& v);

		friend int GetN ();
		friend ostream& operator << (ostream &cout, const CDot& v);
		friend istream& operator >> (istream &cin, const CDot& v);
		friend class CCircle;
};

class CCircle
{
	private:
		int r;
		CDot d;

	public:
		CCircle ()
		{
			SetZero ();
		}

		CCircle (int R, int u, int v)
		{
			r = R;
			d.SetDot (u,v);
		}
		CCircle (int R, CDot D)
		{
			r = R;
			d = D;
		}
		
		void SetZero ()
		{
			r = 0;
			d.SetZero();
		}
		void SetCircle (int R, int u, int v)
		{
			r = R;
			d.SetDot (u,v);
		}
		void ShowCircle ();
		CDot GetD ()
		{
			return d;
		}
		int GetR ()
		{
			return r;
		}
		CCircle& operator = (const CCircle& c);

		friend int GetN ();
		friend ostream& operator << (ostream &cout, CCircle& c);
		friend istream& operator >> (istream &cin, CCircle& c);
		friend bool IsInCircle (CDot d, CCircle c);
		friend void BuildCircle (CDot *d, int n);
		friend int FindMax (CDot *d, int n);
		friend CDot* FindMaxD (CDot *d, int n);
		friend class CDot;
};
