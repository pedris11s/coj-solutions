#include <bits/stdc++.h>

using namespace std;

char CadAux[10007];

int main()
{
    //freopen("x.in", "r", stdin);

    int t;
    scanf("%d", &t);
    for(int CASE = 1; CASE <= t; CASE++)
    {
        scanf(" %[^\n]", CadAux);
        string cad = (string)CadAux;
        scanf(" %[^\n]", CadAux);
        string alphabet = (string)CadAux;

        for(int i = 0; i < cad.size(); i++)
            if(cad[i] != ' ')
                cad[i] = alphabet[cad[i] - 'A'];

        cout << CASE << " " << cad << endl;
    }


    return 0;
}
