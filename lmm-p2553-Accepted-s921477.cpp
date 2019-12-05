#include <bits/stdc++.h>
using namespace std;
#define MAXN 40005
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i, a, b) for(int i = a; i < b; i++)
#define FORR(i, n) for(int i = n; i >= 0; i--)
#define pb push_back
#define mp make_pair
typedef long long ll;
int n,s;
vector<int> graph[MAXN];
ll sol[MAXN];
ll aux[MAXN];
ll dp[MAXN];
queue<int> cola;
void bfs(int n)
{
    cola.push(n);
    dp[n] = 1;
    while(!cola.empty())
    {
        int u = cola.front();
        cola.pop();
        FOR(i, graph[u].size())
        {
            int v = graph[u][i];
            dp[v] = max(dp[v], dp[u]+sol[v]);
            cola.push(v);
            //cout << "dp["<<v<<"] = "<<dp[v]<<endl;
        }
    }
}
int main()
{
    SDD(n,s);
    FOR(i, s)
    {
        int a,b;
        SDD(a,b);
        graph[b].pb(a);
    }
    sol[n] = 1;
    for(int i = n; i >= 1; i--)
    {
        int size = graph[i].size();
        for(int j = 0; j < size; j++)
        {
            int v = graph[i][j];
            sol[v]+=sol[i];
        }
    }
    dp[n] = 1;
    for(int i = n; i >= 1; i--)
    {
        int size = graph[i].size();
        for(int j = 0; j < size; j++)
        {
            int v = graph[i][j];
            dp[v] = max(dp[v], dp[i]+sol[v]);
        }
    }
    printf("%lld\n", dp[1]);




    return 0;
}
