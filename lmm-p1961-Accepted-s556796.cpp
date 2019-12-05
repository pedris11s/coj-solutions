#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 105;

int N, M;
int Mat[MAXN][MAXN];
int wayf[MAXN];
int d1, d2;

int dijkstra()
{
    priority_queue <par, vector <par>, greater <par> > cola;
    cola.push(par(0, 1));
    vector <int> costo(MAXN, (1 << 30));
    costo[1] = 0;

    while(!cola.empty())
    {
        int nodo = cola.top().second;
        int cost = cola.top().first;
        cola.pop();

        for(int i = 1; i <= N; i++)
        {
            if(Mat[nodo][i] == 0)continue;
            int nn = i;
            int ncost = Mat[nodo][i] + cost;

            if(costo[nn] > ncost)
            {
                cola.push(par(ncost, nn));
                costo[nn] = ncost;
                wayf[nn] = nodo;
            }

        }
    }
    return costo[N];
}

void build_way()
{
    int ini = 1, fin = N, max = 0;
    vector <int> sol;
    while(ini != fin)
    {
        sol.push_back(fin);
        fin = wayf[fin];
    }
    sol.push_back(ini);

    int a, b, anterior;
    for(int i = 1; i < sol.size(); i++)
    {
        anterior = Mat[sol[i - 1]][sol[i]];

        Mat[sol[i - 1]][sol[i]] *= 2;
        Mat[sol[i]][sol[i - 1]] *= 2;

        int dijks = dijkstra();
        if(d2 < dijks)
            d2 = dijks;

        Mat[sol[i - 1]][sol[i]] = anterior;
        Mat[sol[i]][sol[i - 1]] = anterior;
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Mat[a][b] = Mat[b][a] = c;
    }

    d1 = dijkstra();
    build_way();

    cout << d2 - d1 << endl;




    return 0;
}
