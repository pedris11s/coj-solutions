#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e4 + 7;

int N, M;
bool mk[MAXN];
vector <int> adlist[MAXN];

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

LL sum(LL n)
{
    if(n & 1)
        return ((n + 1) >> 1) * n;
    return (n >> 1) * (n + 1);
}

int main()
{
    //freopen("x.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++)
            adlist[i].clear();

        fill(mk, mk + N + 1, false);

        for(int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            adlist[a].push_back(b);
            adlist[b].push_back(a);
        }
        LL X = 0;
        for(int i = 1; i <= N; i++)
            if(!mk[i])
            {
                ++X;
                bfs(i);
            }
        printf("%lld\n", sum(X - 1));
    }
    return 0;
}
