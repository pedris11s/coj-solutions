#include <bits/stdc++.h>

using namespace std;

typedef long long LL;;
typedef pair <LL, LL> par;

const LL INF = (100000000000000000);

const int MAXN = 107;

int N, K;
LL costo[MAXN];
vector <par> adlist[MAXN];

LL sol()
{
    priority_queue <par, vector <par>, greater <par> >cola;
    for(int i = 1; i <= N; i++)
        costo[i] = INF;

    cola.push(par(0, 1));
    costo[1] = 0;

    while(!cola.empty())
    {
        LL nodo = cola.top().second;
        LL cost = cola.top().first;
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            LL nn = adlist[nodo][i].first;
            LL ncost = adlist[nodo][i].second + cost;

            if(ncost < costo[nn])
            {
                cola.push(par(ncost, nn));
                costo[nn] = ncost;
            }
        }
    }
    return costo[N];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
/*
8 0
5
3
2
6
4
10
5
3 6
2 5*/

    cin >> N >> K;
    for(int i = 1; i <= N - 1; i++)
    {
        LL x;
        cin >> x;
        adlist[i].push_back(par(i + 1, x));
        //adlist[i + 1].push_back(par(i, x));
    }
    for(int i = 0; i < K; i++)
    {
        LL a, b;
        cin >> a >> b;
        adlist[a].push_back(par(b, 1));
        //adlist[b].push_back(par(a, 1));
    }
    cout << sol() << "\n";
    return 0;
}
