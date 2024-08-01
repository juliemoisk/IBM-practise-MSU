#include"include.h"
Cfaction Cfaction::operator+(const Cfaction& other)
{
    Cfaction r;
    if (this->kol > other.kol)
    {
        for (int i = 0; i < other.kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] + this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }

        for (int i = other.kol; i < this->kol; i++)
        {
            r.push_back(this->num[i], this->denum[i]);
        }
    }
    else if (this->kol < other.kol)
    {

        for (int i = 0; i < this->kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] + this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }

        for (int i = this->kol; i < other.kol; i++)
        {
            r.push_back(other.num[i], other.denum[i]);
        }
    }
    else
    {
        for (int i = 0; i < other.kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] + this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }
    }
    r.reduction();
    return r;

}
Cfaction Cfaction::operator-(const Cfaction& other)
{
    Cfaction  r;

    if (this->kol > other.kol)
    {
        for (int i = 0; i < other.kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] - this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }

        for (int i = other.kol; i < this->kol; i++)
        {
            r.push_back(this->num[i], this->denum[i]);
        }
    }
    else if (this->kol < other.kol)
    {

        for (int i = 0; i < this->kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] - this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }

        for (int i = this->kol; i < other.kol; i++)
        {
            r.push_back(other.num[i], other.denum[i]);
        }
    }
    else
    {
        for (int i = 0; i < other.kol; i++)
        {
            r.push_back(other.num[i] * this->denum[i] - this->num[i] * other.denum[i], other.denum[i] * this->denum[i]);
        }
    }
    r.reduction();
    return r;
}
double Cfaction ::operator*(const Cfaction& other)
{
    double  r = 0.0;
    for (int i = 0; i < kol; i++)
        r +=  num[i] * other.num[i]/(double)(denum[i] * other.denum[i]);
    
    return r;
}
void Cfaction::reduction()
{
    int nod;
    for (int i = 0; i < this->kol; i++)
    {
        nod = greatest_common_divisor(this->num[i], this->denum[i]);
        this->num[i] /= nod;
        this->denum[i] /= nod;
    }
}

void Cfaction::Input(string& filename, vector<Cfaction*>& vec, vector<CFabricFaction*>& fab)
{
    int index;
    string name;
    string str;
    ifstream file(filename);
    while (getline(file, str))
    {
        stringstream line(str); line>>index>>name;
        Cfaction* ptr = fab[index - 1]->Create();             
                ptr->Set_name(name);
                while(line>>index)
                {
                    ptr->num.push_back(index);
                    line>>index;
                    ptr->denum.push_back(index);
                }
                ptr->Setkol(ptr->num.size());
		        ptr->reduction();
                vec.push_back(ptr);
    }
    file.close();
}
ostream& operator <<(ostream& cout, const Cfaction& other)
{
    cout << "{ ";
    for (int i = 0; i < other.kol; i++)
    {
        cout << "(" << other.num[i] << "|" << other.denum[i] << ")";
        if (i + 1 != other.kol) cout << " ; ";
    }
    cout << " }\n";
    return cout;
}

void Cfaction1::Output()
{
    ofstream out;
    out.open(name,ios::app);
    if (out.is_open())
    {
        out << "{ ";
        for (int i = 0; i < kol; i++)
        {
            out << "(" << num[i] << "|" << denum[i] << ")";
            if (i + 1 != kol) out << " , ";
        }
        out << " }\n\n";
    }
    out.close();
}

void Cfaction2::Output()
{
    ofstream out;
    out.open(name,ios::app);
    if (out.is_open())
    {
        out << "{ ";
        for (int i = 0; i < kol; i++)
        {
            out << "(" << num[i] << "|" << denum[i] << ")";
            if (i + 1 != kol) out << "\n";
        }
        out << " }\n\n";
    }
    out.close();
}

 void Cfaction::Output()
{
    ofstream out;
    out.open(name,ios::app);
    if (out.is_open())
    {
        out << "print  Cfaction Output\n";
    }
    out.close();

}

int greatest_common_divisor(int a, int b)
{
    a = fabs(a);
    b = fabs(b);
    while (a != 0 && b != 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a + b);
}

