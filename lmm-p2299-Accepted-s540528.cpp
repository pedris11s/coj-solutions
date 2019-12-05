#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1e6 + 7;
const int INF = (1 << 30);

typedef pair <int, int> par;

int F, S, G, U, D;

int sol()
{
    priority_queue <par, vector <par>, greater <par> > cola;
    vector <int> costo(MAX, INF);

    cola.push(par(0, S));
    costo[S] = 0;
    while(!cola.empty())
    {
        int nodo = cola.top().second;
        int cost = cola.top().first;
        cola.pop();

        int nn, ncost;
        if(nodo + U <= F)
        {
            nn = nodo + U;
            ncost = cost + 1;
            if(costo[nn] > ncost)
            {
                costo[nn] = ncost;
                cola.push(par(ncost, nn));
            }
        }

        if(nodo - D >= 1)
        {
            nn = nodo - D;
            ncost = cost + 1;
            if(costo[nn] > ncost)
            {
                costo[nn] = ncost;
                cola.push(par(ncost, nn));
            }
        }
    }
    return costo[G];
}

int main()
{
    cin >> F >> S >> G >> U >> D;

    int answer = sol();
    if(answer != INF)
        cout << answer << endl;
    else
        cout << "use the stairs\n";

    return 0;
}

