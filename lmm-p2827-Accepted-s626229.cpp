#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

LL Fin = 1000000000000000000;

vector <LL> V;

int main()
{
    LL n = 0;
    V.push_back(0);
    V.push_back(1);
    int ind = 2;
    while(n <= Fin)
    {
        n = V[ind - 1] + V[ind - 2];
        V.push_back(n);
        ind++;
    }
    //for(int i = 0; i < V.size(); i++)
    //    cout << V[i] << endl;
    LL N;
    while(cin >> N)
    {
        LL aux = N;
        vector <LL> Sol;
        while(N > 0)
        {
            LL x = upper_bound(V.begin(), V.end(), N) - V.begin();
            Sol.push_back(V[x - 1]);
            N -= V[x - 1];
        }

        cout << aux << " = ";
        for(int i = Sol.size() - 1; i > -1; i--)
            if(i > 0)
                cout << Sol[i] << " + ";
            else
                cout << Sol[i] << endl;

    }




    return 0;
}

