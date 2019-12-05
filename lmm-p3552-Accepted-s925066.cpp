//3552

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b)  for(int i = a; i < b; i++)
#define zero(n) memset(n, 0, sizeof(n))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAXN 100005


namespace hk{
    const int M=50005;
    const int nil=0;
    const int oo=(1<<28);
    vector< int > G[M];
    int mm[M], d[M];
    // n: number of nodes on left side, nodes are numbered 1 to n
    // m: number of nodes on right side, nodes are numbered n+1 to n+m
    // G = nil[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]
    void init(){
        for(int i=0;i<M;i++)G[i].clear();
        zero(mm);zero(d);
    }
    bool bfs(int n) {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++)
            if(mm[i]==nil) {
                d[i] = 0;
                Q.push(i);
            }
            else d[i] = oo;
        d[nil] = oo;
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
            if(u!=nil) {
                len = G[u].size();
                for(i=0; i<len; i++) {
                    v = G[u][i];
                    if(d[mm[v]]==oo) {
                        d[mm[v]] = d[u] + 1;
                        Q.push(mm[v]);
                    }
                }
            }
        }
        return (d[nil]!=oo);
    }
    bool dfs(int u) {
        int i, v, len;
        if(u!=nil) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(d[mm[v]]==d[u]+1)
                    if(dfs(mm[v])) {
                        mm[v] = u;
                        mm[u] = v;
                        return true;
                    }
            }
            d[u] = oo;
            return false;
        }
        return true;
    }
    int hopcroft_karp(int n) {
        int matching = 0, i;
        // mm[] is assumed nil for all vertex in G
        while(bfs(n))
            for(i=1; i<=n; i++)
                if(mm[i]==nil && dfs(i))
                    matching++;
        return matching;
    }
    void add(int a,int b){
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
int n,m;
int rango = 10004;
int main()
{
    while(SDD(n,m)!=EOF)
    {
        if(!n && !m)break;
        hk::init();
        int a, b;
        FOR(i, m)
        {
            SDD(a,b);
            a++,b++;
            b+=rango;
            hk::add(a,b);
        }
        printf("%d\n", hk::hopcroft_karp(n));
    }
    return 0;
}
