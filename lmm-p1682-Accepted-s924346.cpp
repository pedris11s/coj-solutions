#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i,a,b)  for(int i = a; i < b; i++)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 10005

int n;
ll piles[MAXN];
ll mark[MAXN];
ll sg[MAXN];

ll val;
int main()
{
    for(int i = 0; i <= 3; i++)
    {
        sg[i] = i;
    }
    FAB(i, 4, MAXN)
    {
        for(int j = 1; j <= i/2; j++)
        {
            ll SG = sg[i-j]^sg[j-1];
            mark[SG] = i;
            int next = j+1;
            SG = sg[next-2] ^ sg[i-next];
            mark[SG] = i;
            next = j+2;
            SG = sg[next-3] ^ sg[i-next];
            mark[SG] = i;
        }
        for(int j = 0; j <= i; j++)
        {
            if(mark[j]!=i)
            {
                sg[i] = j;
                break;
            }
        }
    }
    int t, n;
    SD(t);
    while(t--)
    {
        SD(n);
        ll sol = 0;
        FOR(i, n)
        {
            SD(val);
            sol ^= sg[val];
        }
        if(sol)
        {
            printf("MIRKO\n");
        }else{
            printf("SLAVKO\n");
        }
    }
    return 0;
}
