#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1e10;
#define MAXN 1000005

int t,n;
int primos[MAXN];
int cnt;
int band = 0;
ll dp[MAXN];
bool visited[MAXN];
int main()
{
    //printf("%.10lld\n", 230040000001LL%MOD);
    scanf("%d", &t);
    for(int i = 2; i*i<MAXN; i++)
    {
        if(!visited[i])
        {
            for(int j = i*i; j < MAXN; j+=i)
            {
                visited[j] = true;
            }
        }
    }
    for(int i = 2; i < MAXN; i++)
    {
        if(!visited[i])
        {
            primos[cnt++] = i;
        }
    }
    dp[2] = 2;
    bool ok = true;
    for(int i = 3; i < MAXN; i++)
    {
        if(!visited[i])
        {
            dp[i] = dp[i-1]*(ll)i;
            if(dp[i]>MOD)
            {
                if(ok){
                    band = i;
                    ok = false;
                }
                dp[i]%=MOD;

            }
        }else{
            dp[i] = dp[i-1];
        }
    }
    while(t--)
    {
        scanf("%d", &n);
        if(n<band)
        {
            printf("%lld\n", dp[n]);
        }else{
            printf("%.10lld\n", dp[n]);
        }
    }



    return 0;
}
