#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005

int dp[9][9][9][9];
bool marca[9][9][9][9];

bool solve(int a, int b, int c, int d)
{
    if(marca[a][b][c][d]) return dp[a][b][c][d];
    marca[a][b][c][d] = true;
    bool solv = false;
    if(a>=2 && b>=1 && d>=2)
    {
        if(!solve(a-2,b-1,c, d-2))
        {
            solv = true;
            return dp[a][b][c][d] = true;
        }
    }
    if(a>=1 && b>=1 && c>=1 && d>=1)
    {
        if(!solve(a-1,b-1,c-1,d-1))
        {
            solv = true;
            return dp[a][b][c][d] = true;
        }
    }
    if(c>=1 && d>=1)
    {
        if(!solve(a,b,c-1,d-1))
        {
            solv = true;
            return dp[a][b][c][d] = true;
        }
    }
    if(b>=3)
    {
        if(!solve(a,b-3,c,d))
        {
            solv = true;
            return dp[a][b][c][d] = true;
        }
    }
    if(a>=1 && d>=1)
    {
        if(!solve(a-1,b,c,d-1))
        {
            solv = true;
            return dp[a][b][c][d] = true;
        }
    }
    return dp[a][b][c][d] = solv;
}
int main()
{
    int t,a,b,c,d;
    SD(t);
    while(t--)
    {
        scanf("%d%d%d%d", &a,&b,&c,&d);
        if(solve(a,b,c,d))
        {
            printf("Patrick\n");
        }else{
            printf("Roland\n");
        }
    }

    return 0;
}
