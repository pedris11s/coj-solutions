#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> par;

const int MAXN = 10005;
const int INF = (1 << 29);

int N, M, K;
bool isMarket[MAXN];
int markets[MAXN], costo[5][MAXN], A[5];
vector <par> adlist[MAXN];

void dijkstra(int nodo)
{
    priority_queue <par, vector <par>, greater <par> > cola;
    cola.push(par(0,  markets[nodo]));

    while(!cola.empty())
    {
        int nod = cola.top().second;
        int cost = cola.top().first;
        cola.pop();

        if(costo[nodo][nod] <= cost)
                continue;

        costo[nodo][nod] = cost;
        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i].first;
            int ncost = adlist[nod][i].second + cost;

            if(costo[nodo][nn] > ncost)
                cola.push(par(ncost, nn));
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        cin >> markets[i];
        markets[i]--;
        isMarket[markets[i]] = true;
    }

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adlist[a].push_back(par(b, c));
        adlist[b].push_back(par(a, c));
    }

    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
            costo[i][j] = INF;
        dijkstra(i);
    }

    int sol = INF;
    for(int i = 0; i < K; i++)
        A[i] = i;

    do
    {
        int sum = INF;
        for(int i = 0; i < N; i++)
            if(!isMarket[i])
                sum = min(sum, costo[A[0]][i] + costo[A[K - 1]][i]);

        for(int i = 1; i < K; i++)
            sum += costo[A[i - 1]][markets[A[i]]];

        sol = min(sol, sum);

    }while(next_permutation(A, A + K));

    cout << sol << endl;
/*
    cout << endl << endl;
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
            cout << costo[i][j] << ' ';
        cout << endl;
    }*/

    return 0;
}
