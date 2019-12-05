#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

typedef pair <int, int> par;

struct trio{
    int nod, cost, k;
    trio(int x = 0, int y = 0, int z = 0)
    {
        nod = x, cost = y, k = z;
    }
    bool operator < (const trio &p)const
    {
        if(cost != p.cost)
            return cost > p.cost;
    }
};

int N, M, K;
int costo[MAXN][25];
vector <par> adlist[MAXN];

int dijkstra()
{
    priority_queue <trio> cola;
    cola.push(trio(1, 0, 0));

    for(int i = 0; i <= N; i++)
        for(int j = 0; j <= K; j++)
            costo[i][j] = (1 << 30);

    costo[1][0] = 0;
    while(!cola.empty())
    {
        int nodo = cola.top().nod;
        int cost = cola.top().cost;
        int cantk = cola.top().k;
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i].first;
            int ncost = adlist[nodo][i].second + cost;
            if(costo[nn][cantk] > ncost)
            {
                costo[nn][cantk] = ncost;
                cola.push(trio(nn, ncost, cantk));
            }

            if(cantk + 1 <= K)
            {
                if(costo[nn][cantk + 1] > costo[nodo][cantk])
                {
                    costo[nn][cantk + 1] = costo[nodo][cantk];
                    cola.push(trio(nn, costo[nn][cantk + 1], cantk + 1));
                }
            }
        }
    }
    return costo[N][K];
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adlist[a].push_back(par(b, c));
        adlist[b].push_back(par(a, c));
    }
    cout << dijkstra() << endl;

    return 0;
}
