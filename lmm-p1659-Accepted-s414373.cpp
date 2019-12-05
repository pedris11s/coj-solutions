#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAXF = 501;
const int INF = 2000000;

typedef pair <int, int> pii;

#define MKP(a, b) make_pair((a), (b))

int F, P, C, M;
set <int> plad;
vector <pii> adlist[MAXF];
priority_queue <pii, vector <pii>, greater <pii> > cola;

int Dijkstra(int ini, int dest)
{
    while(!cola.empty())
        cola.pop();

    vector <int> costo(MAXF, INF);
    costo[ini] = 0;

    cola.push(MKP(0, ini));
    while(!cola.empty())
    {
        int cost = cola.top().first;
        int nodo = cola.top().second;
        cola.pop();

        for(int i = 0; i < adlist[nodo].size(); i++)
        {
            int next = adlist[nodo][i].second;
            int ncost = adlist[nodo][i].first + cost;
            if(costo[next] > ncost)
            {
                costo[next] = ncost;
                cola.push(MKP(costo[next], next));
            }
        }
    }
    return costo[dest];
}

int main()
{
    //freopen("alibi.in", "r", stdin);
    //freopen("alibi.out", "w", stdout);

    cin >> F >> P >> C >> M;
    for(int i = 0; i < P; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adlist[a].push_back(MKP(c, b));
        adlist[b].push_back(MKP(c, a));
    }
    for(int i = 1; i <= C; i++)
    {
        int n;
        cin >> n;
        int dist = Dijkstra(n, 1);
        if(dist <= M)
            plad.insert(i);
    }
    cout << plad.size() << endl;
    for(set <int> :: iterator it = plad.begin(); it != plad.end(); it++)
        cout << (*it) << endl;


    return 0;
}
