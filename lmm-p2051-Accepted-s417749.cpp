#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


char M[30][30];
vector <string>v;

int main()
{
    int F, C;
    cin >> F >> C;
    for(int i = 0; i < F; i++)
        scanf("%s", M[i]);

    for(int i = 0; i < F; i++)
    {
        string aux = "";
        for(int j = 0; j < C; j++)
        {
            if(M[i][j] == '#' && aux.length() > 1)
            {
                v.push_back(aux);
                aux = "";
                continue;
            }
            else if(M[i][j] == '#' && aux.length() < 2)
            {
                aux = "";
                continue;
            }
            aux += M[i][j];
        }
        if(aux.length() > 1)
            v.push_back(aux);
    }

    for(int j = 0; j < C; j++)
    {
        string aux = "";
        for(int i = 0; i < F; i++)
        {
            if(M[i][j] == '#' && aux.length() > 1)
            {
                v.push_back(aux);
                aux = "";
                continue;
            }
            else if(M[i][j] == '#' && aux.length() < 2)
            {
                aux = "";
                continue;
            }
            aux += M[i][j];
        }
        if(aux.length() > 1)
            v.push_back(aux);
    }

    sort(v.begin(), v.end());

    cout << v[0] << endl;

    return 0;
}
