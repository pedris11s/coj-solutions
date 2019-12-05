//3384
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b)  for(int i = a; i < b; i++)
#define zero(n) memset(n, 0, sizeof(n))
#define sz size()
#define mone(n) memset(n, -1, sizeof(n))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXN 10005

int N, M, R, E;
bool mk[MAXN];
vector <int> adlist[MAXN];


pair <int, int> bfs(int nodo)
{
    int NODOS = 0;
    int EDGES = 0;

    queue <int> cola;
    cola.push(nodo);
    mk[nodo] = true;
    while(!cola.empty())
    {
        int nod = cola.front();
        cola.pop();

        NODOS++;

        for(int i = 0; i < adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            EDGES++;
            if(mk[nn])continue;

            cola.push(nn);
            mk[nn] = true;
        }
    }
    return mp(NODOS, EDGES / 2);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> R >> E;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adlist[a].push_back(b);
        adlist[b].push_back(a);
    }

    int sol = 0;
    for(int i = 1; i <= N; i++)
        if(!mk[i])
        {
            pair <int, int> x = bfs(i);
            int nod = x.first;
            int aris = x.second;
            sol += min(nod * E, ((nod * (nod - 1) /  2) - aris) * R);
        }
    cout << sol << "\n";

    return 0;
}
