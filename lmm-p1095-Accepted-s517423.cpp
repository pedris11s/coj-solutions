#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 7;

bool mk[MAXN];
vector <int> adlist[MAXN];
int N, M, K, grado[MAXN], G[MAXN];

void bfs(int nodo)
{
    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();

        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
        }
    }
}

void ordena(int nodo)
{
    mk[nodo] = true;
    for(int i = 0; i < adlist[nodo].size(); i++)
        if(!mk[adlist[nodo][i]])
            ordena(adlist[nodo][i]);

    G[K] = nodo;
    K--;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M;

        for(int i = 0; i <= N; i++)
            adlist[i].clear();

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            grado[b++];
        }
        int cont = 0;
        fill(mk, mk + N + 1, false);

        K = N;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                ordena(i);

        fill(mk, mk + N + 1, false);
        for(int i = 1; i <= N; i++)
            if(!mk[G[i]])
            {
                bfs(G[i]);
                cont++;
            }
        cout << cont << endl;

    }

    return 0;
}


