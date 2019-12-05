#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 20001;

int N, M;
int costo[MAXN];
bool mk[MAXN];
queue <int> cola;
vector <int> adlist[MAXN];

void BFS()
{
    while(!cola.empty())
        cola.pop();

    for(int i = 0; i < MAXN; i++)
        costo[i] = mk[i] = 0;

    int maxd = 0;

    cola.push(1);
    mk[1] = true;
    while(!cola.empty())
    {
        int nodo = cola.front();
        cola.pop();

        for(int i = 0; i < (int)adlist[nodo].size(); i++)
        {
            int nn = adlist[nodo][i];
            if(mk[nn])
                continue;

            cola.push(nn);
            mk[nn] = true;
            costo[nn] = costo[nodo] + 1;
            maxd = max(maxd, costo[nn]);
        }
    }
    bool flag = true;
    int nodo_sol, cnodos = 0;

    //for(int i = 1; i <= N; i++)
    //    cout << costo[i] << ' ';
    //cout << endl << endl;;

    for(int i = 1; i <= N; i++)
        if(costo[i] == maxd)
        {
            if(flag)
            {
                nodo_sol = i;
                flag = false;
            }
            cnodos++;
        }
    cout << nodo_sol << ' ' << maxd << ' ' << cnodos << endl;
}

int main()
{
    //freopen("d.in", "r", stdin);
    //freopen("d.out3", "w", stdout);

    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < MAXN; i++)
            adlist[i].clear();

        cin >> N >> M;
        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }
        BFS();
    }

    return 0;
}
