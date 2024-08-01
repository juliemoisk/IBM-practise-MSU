#include"include.h"
#include "function.cpp"

int main(void)
{
    srand(time(NULL));
    string name;
 /*   Cfaction X(3), Y(3), R, T;
    X.rand_faction();Y.rand_faction();
    cout<<X<<Y;
    T = X+Y;
    cout<<T;
    R = X-Y;
    cout<<R;
    cout<<X<<Y;//*/

 /*   Cfaction1 M(4);
    Cfaction1 M1(4);
    Cfaction2 P(4);
    M.rand_faction();
    M1.rand_faction();
    P.rand_faction();
    cout<<M;
    cout<<M1;
    cin>>name;
     M.Output(name);
     cout << P;
     cin >> name;
     P.Output(name);
     cout <<"< M; M1 > = " << M * M1 << endl;
     */
     vector<Cfaction*> vec;
     vector<CFabricFaction*> fab;
     fab.push_back(new CFabricFaction1); fab.push_back(new CFabricFaction2);
     cin >> name;
     Cfaction::Input(name, vec,fab);

     for (size_t i = 0; i < vec.size(); i++)
     {
         vec[i]->Output();
         cout << *vec[i] << endl;
     }
     for (size_t i = 0; i < vec.size(); i++) delete vec[i];
     for (size_t i = 0; i < fab.size(); i++) delete fab[i];
    return 0;
}

