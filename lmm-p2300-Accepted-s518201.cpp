#include <cstdio>
#include <iostream>

using namespace std;

string L[15];
int Value[15];

void build()
{

    L[2] = "ABC";
    L[3] = "DEF";
    L[4] = "GHI";
    L[5] = "JKL";
    L[6] = "MNO";
    L[7] = "PQRS";
    L[8] = "TUV";
    L[9] = "WXYZ";

    Value[1] = 2;
    for(int i = 2; i < 10; i++)
        Value[i] = Value[i - 1] + 1;
}

int dame_ind(char c)
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < L[i].size(); j++)
            if(L[i][j] == c)
                return i;
}

int main()
{
    build();

    string cad;
    cin >> cad;
    int sol = 0;
    for(int i = 0; i < cad.size(); i++)
    {
        int ind = dame_ind(cad[i]);
        sol += Value[ind];
    }
    cout << sol << endl;

    return 0;
}
