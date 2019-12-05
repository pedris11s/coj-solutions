#include <bits/stdc++.h>

using namespace std;

vector <string> W;

void DivideWords(string cad)
{
    int i = 0;
    string p = "";
    while(i < cad.size())
    {
        if(cad[i] == ' ')
        {
            W.push_back(p);
            p = "";
        }
        else if(i == cad.size() - 1)
        {
            p += cad[i];
            W.push_back(p);
            p = "";
        }
        else
            p += cad[i];
        i++;
    }
}

int main()
{
    //freopen(".en", "r", stdin);

    char CadAux[10000];
    scanf(" %[^\n]", CadAux);

    string cad = (string)CadAux;
    DivideWords(cad);
    //for(int i = 0; i < W.size(); i++)
    //    cout << W[i] << ' ';
    for(int i = 0; i < W.size(); i++)
    {
        string p = "";
        for(int j = 0; j < W[i].size(); j++)
            p += tolower(W[i][j]);

        if(p == "kroketten")
            W[i] = "croqueta";
    }
    cout << W[0];
    for(int i = 1; i < W.size(); i++)
        cout << ' ' << W[i];

    return 0;
}
