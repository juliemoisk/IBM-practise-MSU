#include <iostream>
#include <math.h>
#include "CClasses.h"
using namespace std;

void CDot::ShowDot () 
{
	cout << "Dot {";
	for (int i = 0; i < 2; i++)
	{
		if (i < 1)
		{
			cout << x << ", ";
		}
		else
		{
			cout << y;
		}
	}
	cout << "}\n";
}

//-----------------------------------------------------------------------------------------------------------------------------------

CDot& CDot:: operator = (const CDot& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

//-----------------------------------------------------------------------------------------------------------------------------------

void CCircle::ShowCircle()
{
	cout << "Circle { radius: " << r << ", center: " << d.Get_x() << ", " << d.Get_y();
	cout << "}\n";
}	

//-----------------------------------------------------------------------------------------------------------------------------------

CCircle& CCircle:: operator = (const CCircle& c)
{
	r = c.r;
	d = c.d;
	return *this;
}

//-----------------------------------------------------------------------------------------------------------------------------------

ostream& operator << (ostream &cout, const CDot& v)
{
	cout << "Dot {";
	for (int i = 0; i < 2; i++)
	{
		if (i < 1)
		{
			cout << v.x << ", ";
		}
		else
		{
			cout << v.y;
		}
	}
	cout << "}\n";	
	return cout;
}

//-----------------------------------------------------------------------------------------------------------------------------------

istream& operator >> (istream &cin, CDot& v)
{
	int x, y;
	cout << "Please, enter the x - coordinate: ";
	cin >> x;
	cout << "Please, enter the y - coordinate: ";
	cin >> y;
	CDot a(x,y);
	v = a;
	return cin;
}

//-----------------------------------------------------------------------------------------------------------------------------------

ostream& operator << (ostream &cout, CCircle& c)
{
	cout << "Circle {radius: "<< c.GetR() << ", center: " << c.GetD().Get_x() << ", " << c.GetD().Get_y();
	cout << "}\n";
	return cout;
}

//-----------------------------------------------------------------------------------------------------------------------------------

istream& operator >> (istream &cin, CCircle& c)
{
	int x, y, r;
	cout << "Please, enter the x - coordinate: ";
	cin >> x;
	cout << "Please, enter the y - coordinate: ";
	cin >> y;
	cout << "Please, enter the radius r: ";
	cin >> r;
	CCircle a(r, x, y);
	c = a;
	return cin;
}

//-----------------------------------------------------------------------------------------------------------------------------------

int GetN ()
{
	int n;
	cout << "PLease, enter the amount of dots: ";
	cin >> n;
	return n;
}

//-----------------------------------------------------------------------------------------------------------------------------------

bool IsInCircle (CDot d, CCircle c)
{
	bool flag;
	if ((d.Get_x() - c.GetD().Get_x())*(d.Get_x() - c.GetD().Get_x())
	 + (d.Get_y() - c.GetD().Get_y())*(d.Get_y() - c.GetD().Get_y()) <= c.GetR() * c.GetR())
	{
		return 1;
	}
	else return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------

int FindMax (CDot*d, int n)
{
	if (d == NULL)
	{
		cout << "Dot is empty! ";
		return 0;
	}
	else
	{
		int r;
		int max_r = 0;
		int*x = new int[n];
		int*y = new int[n];
		for (int k = 0; k < n; k++)
		{
			x[k] = d[k].Get_x();
			y[k] = d[k].Get_y();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				r = sqrt ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				if (r > max_r) 
				{
					max_r = r;
				}
			}
		}
		delete[] x;
		delete[] y;
		return max_r;
	}
} 

//-----------------------------------------------------------------------------------------------------------------------------------

CDot* FindMaxD (CDot*d, int n)
{
	if (d == NULL)
	{
		cout << "Dot is empty! ";
		return 0;
	}
	else
	{       
		int i1, j1;
		int r;
		int max_r = 0;
		int*x = new int[n];
		int*y = new int[n];
		for (int k = 0; k < n; k++)
		{
			x[k] = d[k].Get_x();
			y[k] = d[k].Get_y();
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				r = sqrt ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				if (r > max_r) 
				{
					max_r = r;
					i1 = i;
					j1 = j;
				}
			}
		}
		CDot *b = new CDot[2];
		b[0].SetDot(x[i1], y[i1]);
		b[1].SetDot(x[j1], y[j1]);
		delete[] x;
		delete[] y;
		return b;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------

void BuildCircle (CDot*d, int n)
{
	if (d == NULL)
	{
		cout << "Dot is empty! ";
	}
	else
	{
		if (n == 1) 
		{
			CCircle c(0, d[0].Get_x(), d[0].Get_y());
			cout << c;
		}
		if (n == 2)
		{
			int r = sqrt ((d[0].Get_x() - d[1].Get_x()) * (d[0].Get_x() - d[1].Get_x()) + 
				(d[0].Get_y() - d[1].Get_y()) * (d[0].Get_y() - d[1].Get_y()));
			CCircle c (r/2, (d[0].Get_x() + d[1].Get_x()) / 2,(d[0].Get_y() + d[1].Get_y()) / 2);
			cout << c;
		}
		if (n > 2)
		{
			int flag = 0;
			int diam = FindMax(d,n);
			CDot*b = FindMaxD(d,n);
			CCircle c (diam / 2, (b[0].Get_x() + b[1].Get_x())/2,(b[0].Get_y() + b[1].Get_y())/2);
			delete[] b;

			for (int i = 0; i < n; i++)
			{
				if (IsInCircle(d[i], c)) flag ++;
			}
			if (flag == n) cout << c;
			else
			{
				double sx = 0, sy = 0, mx = 0;
				for (int i = 0; i < n; i++)
				{
					sx = sx + d[i].Get_x();
					sy = sy + d[i].Get_y();	
				}
				sx = sx/n;
				sy = sy/n;
				mx = ((sx - d[0].Get_x()) * (sx - d[0].Get_x()) + (sy - d[0].Get_y()) * (sy - d[0].Get_y()));
				for (int i = 0; i < n; i++ )
				{
					if (((sx - d[i].Get_x()) * (sx - d[i].Get_x()) + (sy - d[i].Get_y()) * (sy - d[i].Get_y()))
					    > mx)
					{
						mx = (sx - d[i].Get_x()) * (sx - d[i].Get_x()) + (sy - d[i].Get_y()) * (sy - d[i].Get_y());
					}
				}
				mx = sqrt(mx);
				CCircle cir (mx, sx, sy);
				cout << cir;
			}
		}
	}
}







					
		






















	










