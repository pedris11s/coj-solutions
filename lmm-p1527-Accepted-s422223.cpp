#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 107;

struct par{
    int id, cost;
    bool operator < (const par &X)const
    {
        if(cost != X.cost)
            return cost < X.cost;
        return id < X.id;
    }
}costo[MAXN];

vector <int> sol[MAXN];
vector <int> adlist[MAXN];

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
        {
            bool n;
            cin >> n;
            if(n)
                adlist[i].push_back(j);
        }

    queue <int> cola;
    cola.push(K);
    costo[K].cost = 1;
    int MaxC = 1;
    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < (int)adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(costo[nn].cost != 0)
                continue;

            costo[nn].cost = costo[nodo].cost + 1;
            if(costo[nn].cost > MaxC)
                MaxC = costo[nn].cost;

            cola.push(nn);
        }
    }
    for(int i = 1; i <= N; i++)
        sol[costo[i].cost].push_back(i);

    for(int i = 1; i <= MaxC; i++)
    {
        for(int j = 0; j < (int)sol[i].size(); j++)
            if(j != (int)sol[i].size() - 1)
                cout << sol[i][j] << ' ';
            else
                cout << sol[i][j] << endl;
    }

    return 0;
}
