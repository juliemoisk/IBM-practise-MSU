#include <iostream>
#include <stdio.h> 
#include <string.h>
using namespace std;

class Dist;

//------------------------------------------------------------------------------------------------------------------------------------

class Point {
	int u, v;
	public:
		Point ( int u = 0, int v = 0) { // "начальная" точка
			this -> u = u;
			this -> v = v;
		}
		Point &operator=(const int &u) {
			this -> u = u;
			this -> v = v; 
			return *this;
		}

	        friend ostream &operator<< (ostream &cout, Point &u); // реализовано далеe
		friend istream &operator>> (istream &cin, Point &u);  // реализовано далее
		friend Point operator+ (const Point &u, const Dist &v); // точка + вектор = точка
		friend Point operator+ (const Dist &v, const Point &u); // вектор + точка = вектор
		friend Dist operator- (const Point &u, const Point &v); // точка - точка = вектор
};

//------------------------------------------------------------------------------------------------------------------------------------

class Dist {
	int u, v;
	public:
	Dist ( int u = 0, int v = 0) { // "начальный" вектор
		this -> u = u;
		this -> v = v;
	}
	Dist &operator = (const int &u) {
		this -> u = u;
		this -> v = v;
		return *this;
	}
	Dist operator+ (const Dist &p) { // вектор + вектор = вектор
		Dist r;
		r.u = u + p.u;
		r.v = v + p.v;
		return r;
	}
	friend Dist operator* (const int &p, const Dist &v); // число * вектор = векто		
	friend ostream &operator<< (ostream &cout, Dist &u); // реализовано далее
	friend istream &operator>> (istream &cin, Dist &u);  // реализовано далее
	friend Point operator+ (const Point &u, const Dist &v); // точка + вектор = точка
	friend Point operator+ (const Dist &v, const Point &u); // вектор + точка = вектор
	friend Dist operator- (const Point &u, const Point &v); // точка - точка = вектор
};
	
//------------------------------------------------------------------------------------------------------------------------------------

ostream &operator<< (ostream &cout, Point &u) {
	cout << "( " << u.u << " , " << u.v << " )";
	return cout;
}

istream &operator>> (istream &cin, Point &u) {
	cin >> u.u >> u.v;
	return cin;
}

//------------------------------------------------------------------------------------------------------------------------------------

ostream &operator<< (ostream &cout, Dist &u) {
	cout << "( " << u.u << " , " << u.v << " )";
	return cout;
}

istream &operator>> (istream &cin, Dist &u) {
	cin >> u.u >> u.v;
	return cin;
}

//------------------------------------------------------------------------------------------------------------------------------------

Point operator+ (const Point &u, const Dist &v) { // точка + вектор = точка
	Point r; 
	r.u = v.u + u.u;
	r.v = v.v + u.v;
	return r;
}

Point operator+ (const Dist &v, const Point &u) { // вектор + точка = вектор
	Point r; 
	r.u = v.u + u.u;
	r.v = v.v + u.v;
	return r;
}

Dist operator- (const Point &u, const Point &v) { // точка - точка = вектор
	Dist r;
	r.u = u.u - v.u;
	r.v = u.v - v.v;
	return r;
}

Dist operator* (const int &p, const Dist &v) { // число * вектор = вектор
	Dist r;
	r.u = p * v.u;
	r.v = p * v.v;
	return r;
}

//------------------------------------------------------------------------------------------------------------------------------------

int main (void) {
	cout << "Now we'll test out prog and you'll need to enter several different integers for each test. So prepare yourself and Good Luck!" << endl;
	cout << endl;
	cout << "If you are ready, press ENTER"<<endl;
	cin.get();

	try {
		cout << "\nDeclaration of points test: "<<endl;
		Point p1, p;
		cout << "\tp1 = " << p1 << " " << "=> default checked " << endl;
		cout << "\n\tPlease, enter 2 coordinates for point p. Entered coordinates: ";
		cin >> p;
		cout << endl;
		cout << "\tp = " << p <<" " << "=> checked" << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	try {
		cout << "\nDeclaration of vectors test: "<<endl;
		Dist v1, v;
		cout << "\tv1 = " << v1 << " " << "=> default checked " << endl;
		cout << "\n\tPlease, enter 2 coordinates for vector v. Entered coordinates: ";
		cin >> v;
		cout << endl;
		cout << "\tv = " << v <<" " << "=> checked" << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	cout << "\nNotion: we also checked input and output for point and vector" << endl;

	try {
		cout << "\nSum of a point and a vector test: "<<endl;
		Dist v;
		Point x, sum;
		cout << "\n\tPlease, enter 2 coordinates for point x. Entered coordinates: ";
		cin >> x;
		cout << "\tx = " << x << endl;
		cout << "\n\tPlease, enter 2 coordinates for vector v. Entered coordinates: ";
		cin >> v;
		cout << "\tv = " << v << endl;
		cout << endl;
		sum = x + v;
		cout << "\tThe result sum of point x and vector v is vector sum:" << endl;
		cout << "\tsum = " << sum << " => checked" << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	try {
		cout << "\nSum of a vector and a point test: "<<endl;
		Dist v;
		Point x, sum;
		cout << "\n\tPlease, enter 2 coordinates for vector v. Entered coordinates: ";
		cin >> v;
		cout << "\tv = " << v << endl;
		cout << "\n\tPlease, enter 2 coordinates for point x. Entered coordinates: ";
		cin >> x;
		cout << "\tx = " << x << endl;
		cout << endl;
		sum = v + x;
		cout << "\tThe result sum of vector v and point x is vector sum:" << endl;
		cout << "\tsum = " << sum << " => checked" << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	try {
		cout << "\nDifference of 2 points test: "<<endl;
		Dist v;
		Point x, y;
		cout << "\n\tPlease, enter 2 coordinates for point x. Entered coordinates: ";
		cin >> x;
		cout << "\tx = " << x << endl;
		cout << "\n\tPlease, enter 2 coordinates for point y. Entered coordinates: ";
		cin >> y;
		cout << "\ty = " << y << endl;
		cout << endl;
		v = x - y;
		cout << "\tThe result difference of point x and point y is vector v:" << endl;
		cout << "\tv = " << v << " => checked "<< endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	try {
		cout << "\nSum of 2 vectors test: "<<endl;
		Dist u, v, sum;
		cout << "\n\tPlease, enter 2 coordinates for vector u. Entered coordinates: ";
		cin >> u;
		cout << "\tu = " << u << endl;
		cout << "\n\tPlease, enter 2 coordinates for vector v. Entered coordinates: ";
		cin >> v;
		cout << "\tv = " << v << endl;
		cout << endl;
		sum = u + v;
		cout << "\tThe result sum of vector u and vector v:" << endl;
		cout << "\tsum = " << sum << " => checked" << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	try {
		cout << "\nMultiplication of an integer number and a vector test: "<<endl;
		Dist v, mult;
		int p;
		cout << "\n\tPlease, enter 2 coordinates for vector v. Entered coordinates: ";
		cin >> v;
		cout << "\tv = " << v << endl;
		cout << "\n\tPlease, enter any integer number. You entered: ";
		cin >> p;
		cout << endl;
		mult = p * v;;
		cout << "\tThe result product of integer p and vector v is vector mult:" << endl;
		cout << "\tmult = " << mult << " => checked " << endl;
	}
	catch (int error) {
		cout << "Error = " << error << endl;
	}

	cout << "\nWell Done! "<<endl;
	
	return 0;
}
