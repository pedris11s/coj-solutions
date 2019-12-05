#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;


ll phi(ll n)
{
    ll result = n;
    for(ll i = 2; i*i <= n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            result -= result/i;
        }
    }
    if(n>1)
    {
        result-=result/n;
    }
    return result;
}

int main()
{
    ll num;
    while(scanf("%lld", &num)!=EOF)
    {
        ll aux = num;
        ll aux2 = num+1;
        if(aux%2==0)
        {
            aux/=2;
        }else{
            aux2/=2;
        }
        ll total = (aux*aux2)%MOD;
        total = (total-num+MOD)%MOD;
        ll val = num;
        ll val2 = phi(num);
        if(val%2==0)
        {
            val/=2;
        }else{
            val2/=2;
        }
        ll auxi = (val*val2)%MOD;
        ll sol = (total - auxi+MOD)%MOD;
        printf("%lld\n", sol);
    }



    return 0;
}
