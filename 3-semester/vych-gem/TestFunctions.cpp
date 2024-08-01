#include <iostream> 
#include "CFunctions.cpp"
using namespace std;

void test1 ()
{
	cout << "Test 1\n";
	CDot d1, d2, d3(5,7);
	int x,y;
	cout << "Please, enter x, y: ";
	cin >> x;
	cin >> y;
	d1.SetDot(x,y);
	cout << "d1: ";
	d1.ShowDot();
	cout << "d2: ";
	d2.ShowDot();
	cout << "d3: ";
	d3.ShowDot();
	
	d1 = d2;
	cout << "Now d1 = d2 \n";
	d1.ShowDot();
}

void test2()
{
	cout << "Test 2\n ";
	CDot d(0,1);
	CCircle c1, c2, c3(7,4,2), c4(6, d);
	int x,y,r;
	cout << "Please, enter x, y: ";
	cin >> x;
	cin >> y;
	cout << "Please, enter radius r: ";
	cin >> r;
	c1.SetCircle(r,x,y);
	cout << "c1: ";
	c1.ShowCircle();
	cout << "c2: ";
	c2.ShowCircle();
	cout << "c3: ";
	c3.ShowCircle();
	cout << "c4: ";
	c4.ShowCircle();

	c1 = c4;
	cout << "Now c1 = c4\n";
	c1.ShowCircle();
}   

void test3()
{
	cout << "Test 3\n";
	int r;
	CDot d(0,3), d1;
	CCircle c1, c2, c3(8, 2, 6), c4(8, d);
	cout << "Please, enter c1: ";
	cin >> c1;
	cout << "c1: " << c1;
	cout << "Please, enetr d1: ";
	cin >> d1;
	cout << "d1: " << d1;
	cout << "PLease, enter radius r: ";
	cin >> r;
	cout << "r = " << r << endl;
	cout << "c3: " << c3;
	cout << "c4: " << c4;
	CCircle c5(r,d1);
	cout << "c5: " << c5;  
}

void test4()
{
	cout << "Test 4\n";
	CDot d(0,3), d1;
	CCircle c1, c2, c3(8, 2, 6), c4(8, d);
	cout << "Please, enter c1: ";
	cin >> c1;
	cout << "c1: " << c1;
	cout << "Please, enetr d1: ";
	cin >> d1;
	cout << "d1: " << d1;
	if (IsInCircle(d1,c1)) cout << "Dot d1 is in circle c1\n";
	else cout << "d1 is not in circle c1\n";
}

void test5 ()
{
	cout << "Test 5\n";
	CDot d(0,3);
	CCircle c1, c2, c3(8, 2, 6), c4(8, d);
	int n = GetN();
	CDot*d1 = new CDot[n];
	cout << "Enter d1: ";
	for (int i = 0; i < n; i++)
	{
		cin >> d1[i];
	}
	BuildCircle (d1, n);
	delete[] d1; 
	cout <<"\n";
}


void test6()
{
	cout << "Test 6\n";
	CDot *b, d1(0,100), d2(0,0), d3(300,300);
	b = new CDot[3];
	b[0] = d1; b[1] = d2; b[2] = d3;
	for (int i = 0; i < 3; i++)
	{
		cout << "d1: " << b[i];
	}
	BuildCircle (b,3);
	delete[] b;
}

