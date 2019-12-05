#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10001;

int N, M, Q;
bool mk[MAXN];
queue <int> cola;
vector <int> adlist[MAXN];

int bfs(int nodo)
{
    if(!mk[nodo])
    {
        mk[nodo] = true;
        cola.push(nodo);
    }

    int sol = 0;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();
        sol++;

        for(int i = 0; i < (int)adlist[nod].size(); i++)
        {
            int next = adlist[nod][i];
            if(mk[next])
                continue;

            cola.push(next);
            mk[next] = true;
        }
    }
    return sol;
}


int main()
{
    //freopen("d.in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M >> Q;

        for(int i = 0; i <= N; i++)
            adlist[i].clear();

        fill(mk, mk + N + 1, false);

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
        }
        int sol = 0;
        while(Q--)
        {
            int nod;
            cin >> nod;
            sol += bfs(nod);
        }
        cout << sol << endl;
    }

    return 0;
}
