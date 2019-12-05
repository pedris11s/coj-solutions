#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = (1 << 30);

int N, M, Q;
vector <int> adlist[60];
queue <int> cola;
int deep[60];

void bfs()
{
    while(!cola.empty())
        cola.pop();

    fill(deep, deep + N + 1, INF);

    cola.push(1);
    deep[1] = 1;
    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < (int)adlist[nodo].size(); i++)
        {
            int next = adlist[nodo][i];
            if(deep[next] > deep[nodo] + 1)
            {
                deep[next] = deep[nodo] + 1;
                cola.push(next);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M >> Q;

        for(int i = 0; i <= N; i++)
            adlist[i].clear();

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
        }

        bfs();

        while(Q--)
        {
            int nod;
            cin >> nod;
            if(deep[nod] == INF)
                deep[nod] = -1;

            cout << deep[nod] << endl;
        }
    }

    return 0;
}
