#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 505;

vector <int> adlist[MAXN];
bool mk[MAXN];


bool bfs(int nodo)
{
    int cant_nodos = 0, cant_aristas = 0;

    queue <int> cola;
    cola.push(nodo);

    mk[nodo] = true;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();

        cant_nodos++;

        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            cant_aristas++;
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
        }
    }
    if(cant_nodos - 1 == cant_aristas / 2)
        return true;
    return false;
}

int main()
{
    int tc = 0;
    while(true)
    {
        tc++;
        int N, M;
        cin >> N >> M;

        if(N == M && N == 0)
            break;

        for(int i = 1; i <= N; i++)
            adlist[i].clear();
        fill(mk, mk + N + 1, false);

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }
        int trees = 0;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                if(bfs(i))
                    trees++;

        if(trees == 0)
            printf("Case %d: No trees.\n", tc);
        else if(trees == 1)
            printf("Case %d: There is one tree.\n", tc);
        else if(trees > 1)
            printf("Case %d: A forest of %d trees.\n", tc, trees);
    }

    return 0;
}
