#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1001;

typedef pair <int,int> pii;

#define MKP(a, b) make_pair((a), (b))

int N, M;
int price[MAXN], costo[MAXN];
vector <int> adlist[MAXN];
priority_queue <pii, vector <pii>, greater <pii> > cola;

int Dijkstra()
{
    memset(costo, 63, sizeof costo);
    costo[1] = 0;
    cola.push(MKP(1, 0));
    while(!cola.empty())
    {
        int nodo = cola.top().first;
        int cost = cola.top().second;
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int next = adlist[nodo][i];
            int ncost = cost + price[next];
            if(costo[next] > ncost)
            {
                costo[next] = ncost;
                cola.push(MKP(next, ncost));
            }
        }
    }
    return costo[N];
}

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> price[i];

    price[1] = price[N] = 0;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }
    cout << Dijkstra() << endl;
}
