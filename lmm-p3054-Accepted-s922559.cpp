#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005
ll dp[MAXN];
int main()
{
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i<= 1000000; i++)
    {
        dp[i] = (i*(dp[i-1])%MOD + 1)%MOD;
    }
    int t,n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }

    return 0;
}
