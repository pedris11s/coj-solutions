#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1001;

vector <int> adlist[MAXN];
map <string, int> names;
map <int, string> names2;

bool mk[MAXN];
int value[MAXN];

int bfs(int nodo)
{
    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;
    int max = -1, nodsol;
    while(!cola.empty())
    {
        int nodact = cola.front();
        cola.pop();

        if(value[nodact] > max)
        {
            max = value[nodact];
            nodsol = nodact;
        }

        for(int i = 0; i < adlist[nodact].size(); i++)
        {
            int nn = adlist[nodact][i];
            if(mk[nn])continue;
            cola.push(nn);
            mk[nn] = true;
        }
    }
    return nodsol;
}

int main()
{
    //freopen("ernesto.in", "r", stdin);

    while(true)
    {
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;

        names.clear();
        names2.clear();
        for(int i = 0; i <= N; i++)
            adlist[i].clear();

        fill(mk, mk + N + 1, false);

        for(int i = 1; i <= N; i++)
        {
            int x; string nombre;
            cin >> nombre >> x;
            names[nombre] = i;
            names2[i] = nombre;
            value[i] = x;
        }
        for(int i = 0; i < M; i++)
        {
            string a, b;
            cin >> a >> b;
            adlist[names[a]].push_back(names[b]);
            adlist[names[b]].push_back(names[a]);
        }

        vector <string> nodo_sol;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                nodo_sol.push_back(names2[bfs(i)]);

        sort(nodo_sol.begin(), nodo_sol.end());
        for(int i = 0; i < nodo_sol.size(); i++)
            cout << nodo_sol[i] << endl;
    }
    return 0;
}
