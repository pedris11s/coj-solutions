#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100;

int N, M, Q;
int costo[MAXN];
vector <int> adlist[MAXN];

void dijkstra()
{
    fill(costo, costo + MAXN, INT_MAX);

    queue <int> cola;
    cola.push(1);
    costo[1] = 1;

    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(costo[nn] != INT_MAX)continue;

            cola.push(nn);
            costo[nn] = costo[nodo] + 1;
        }
    }
    for(int i = 0; i < MAXN; i++)
        adlist[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M >> Q;

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
        }
        dijkstra();

        while(Q--)
        {
            int nod;
            cin >> nod;
            if(costo[nod] == INT_MAX)
                cout << "-1\n";
            else
                cout << costo[nod] << "\n";
        }
    }

	return 0;
}
