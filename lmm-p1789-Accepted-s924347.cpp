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
#define MAXN 100005

int t;
pair<int,ll> factor(ll n)
{
    int r = 0;
    int canti = 0;
    ll val = 1;
    for(ll i = 2; i*i <= n; i++)
    {
        while(n%i==0)
        {
            r++;
            canti++;
            if(canti<=2)
            {
                val*=i;
            }
            n/=i;
        }
    }
    if(n>1LL)
    {
        r++;
    }
    return mp(r,val);
}

int main()
{
    ll n;
    int t;
    SD(t);
    while(t--)
    {
        scanf("%lld", &n);
        pair<int,ll> sol = factor(n);
        if(n==1)
        {

            printf("Vasha\n");
            printf("0\n");
            continue;
        }
        if(sol.first==1)
        {
            printf("Vasha\n");
            printf("0\n");
        }
        else if(sol.first>2)
        {
            printf("Vasha\n");
            printf("%lld\n", sol.second);
        }else{
            printf("Molek\n");
        }
    }


    return 0;
}
