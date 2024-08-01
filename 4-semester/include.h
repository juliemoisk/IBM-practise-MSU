#pragma once
#include <iostream>
#include <cstring>
#include <math.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>
#include <iterator>


#define n 10
using namespace std;

int greatest_common_divisor(int a, int b);
class CFabricFaction;
class Cfaction
{
protected:
    vector<int> num; vector<int> denum;
    int kol;
    string name;
public:
    Cfaction() { SetZero(); }
    Cfaction(int kol)
    {
        this->kol = kol;
        num.reserve(kol);
        denum.reserve(kol);
    }
    void rand_faction()
    {
        int nod,x;
            for (int i = 0; i < kol; i++)
            {
                num.push_back(rand() % n);
                x = rand() % n;

                if (x == 0) { x = 1 + rand() % n; }
                denum.push_back(x);

                nod = greatest_common_divisor(num[i], denum[i]);
                num[i] /= nod;
                denum[i] /= nod;
            }
        
    }
    virtual ~Cfaction() { Clean(); }

    void push_back(int num, int denum) { kol++; this->num.push_back(num); this->denum.push_back(denum); }
    void SetZero() { kol = 0; }
    
    void Setkol(int kol){this->kol=kol;}

    void Set_name(string& name) { this->name = name; }

    virtual void Clean() { SetZero(); }

    void CopyOnly(const Cfaction& other) { kol = other.kol;  num.reserve(kol);  denum.reserve(kol); for (int i = 0; i < kol; i++) { num[i] = other.num[i]; denum[i] = other.denum[i]; } }

    Cfaction(const Cfaction& other) { CopyOnly(other); }

   // void Input(string& filename);
    Cfaction& operator= (const Cfaction& other) { if (this != &other) { Clean(); CopyOnly(other); } return *this; }
    Cfaction operator+(const Cfaction& other);
    Cfaction operator-(const Cfaction& other);
    double operator*(const Cfaction& other);
    void reduction();
    static void Input(string& filename, vector<Cfaction*>& vec, vector<CFabricFaction*>& fab);
    friend ostream& operator <<(ostream& cout, const Cfaction& other);
    virtual void Output();
};


class Cfaction1 :public Cfaction
{
    
public:
    Cfaction1() :Cfaction() {}
    Cfaction1(int kol) :Cfaction(kol) {}
    void Output();
    
};
class Cfaction2 :public Cfaction
{
public:
    Cfaction2() :Cfaction() {}
    Cfaction2(int kol) :Cfaction(kol) {}  
    void Output();
};


class CFabricFaction
{
public:
    virtual ~CFabricFaction(){ }
    virtual Cfaction* Create() = 0;

};

class CFabricFaction1 :public CFabricFaction
{
public:
    virtual Cfaction* Create() { return new Cfaction1; }

};

class CFabricFaction2 :public CFabricFaction
{
public:
    virtual Cfaction* Create() { return new Cfaction2; }

};


