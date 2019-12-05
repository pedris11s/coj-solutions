#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

/*
3
10 10
1 2
3 4
2 3
4 5
5 10
6 7
8 9
7 8
9 6
10 1

10 6
1 2
2 1
3 4
4 3
5 6
7 8

10 13
1 2
2 1
3 4
4 3
5 6
6 5
7 8
8 7
9 10
10 9
4 6
5 10
10 1

*/

using namespace std;

const int MAXN = 100001;

int N, M, k;
int grado[MAXN], G[MAXN];
bool mk[MAXN];
vector <int> adlist[MAXN];

void bfs(int nodo)
{
    queue <int> bQ;
    bQ.push(nodo);
    while(!bQ.empty())
    {
        int nod = bQ.front();
        bQ.pop();
        for(int i = 0; i < (int)adlist[nod].size(); i++)
        {
            int nn = adlist[nod][i];
            if(!mk[nn])
            {
                mk[nn] = true;
                bQ.push(nn);
            }
        }
    }
}

void graph_sort(int nodo)
{
    mk[nodo] = true;
    for(int i = 0; i < (int)adlist[nodo].size(); i++)
        if(!mk[adlist[nodo][i]])
            graph_sort(adlist[nodo][i]);

    G[k--] = nodo;
}

int main()
{
    //freopen("d.in", "r", stdin);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> M;

        for(int i = 0; i <= N; i++)
        {
            mk[i] = false;
            adlist[i].clear();
        }

        for(int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            adlist[a].push_back(b);
            grado[b]++;
        }
        k = N;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
                graph_sort(i);

        fill(mk, mk + N + 1, false);

        int sol = 0;
        for(int i = 1; i <= N; i++)
        {
            if(!mk[G[i]])
            {
                bfs(G[i]);
                sol++;
            }
        }
        cout << sol << endl;
    }

    return 0;
}

