#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 50;
const int INF = (1 << 15);

typedef pair <int, int> pii;

int N, costo[MAXN][3], C[MAXN], c;
vector <pii> adlist[MAXN][3];
priority_queue <pii, vector <pii>, greater <pii> > cola;
char q, d, a, b;

void dijkstra(int nod, int p)
{
    //fill(costo[p], costo[p] + 10, INF);
    for(int i = 0; i < MAXN; i++)
        costo[i][p] = INF;

    costo[nod][p] = 0;
    cola.push(pii(0, nod));
    while(!cola.empty())
    {
        int nodo = cola.top().second;
        int cost = cola.top().first;
        cola.pop();

        for(int i = 0; i < (int)adlist[nodo][p].size(); i++)
        {
            int next = adlist[nodo][p][i].first;
            int ncost = cost + adlist[nodo][p][i].second;

            if(costo[next][p] > ncost)
            {
                costo[next][p] = ncost;
                cola.push(pii(ncost, next));
            }
        }
    }
}

int main()
{
    //freopen("d.in", "r", stdin);

    while(true)
    {
        scanf("%d\n", &N);
        if(N == 0)
            break;

        for(int i = 0; i < N; i++)
        {
            scanf("%c %c %c %c %d\n", &q, &d, &a, &b, &c);
            int p = (q == 'Y') ? 1 : 2;
            adlist[a - 'A'][p].push_back(pii(b - 'A', c));
            if(d == 'B')
                adlist[b - 'A'][p].push_back(pii(a - 'A', c));
        }
        char a, b;
        cin >> a >> b;

        dijkstra(a - 'A', 1);
        dijkstra(b - 'A', 2);

        //for(int i = 0; i < N; i++)
        //    cout << costo[i][1] << ' ';
        //cout << endl;

        int dmin = INF;
        for(int i = 0; i < 30; i++)
        {
            C[i] = costo[i][1] + costo[i][2];
            dmin = min(dmin, C[i]);
        }

        if(dmin == INF)
            cout << "You will never meet.\n";
        else
        {
            cout << dmin;
            for(int i = 0; i < 30; i++)
                if(dmin == C[i])
                    cout << ' ' << (char)(i + 'A');
            cout << endl;
        }
        for(int i = 0; i < 30; i++)
            adlist[i][1].clear(), adlist[i][2].clear();
    }
    return 0;
}
