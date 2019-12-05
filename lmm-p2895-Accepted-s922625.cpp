#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005

ll fact_pow(ll n, ll k)
{
    ll res = 0;
    while(n)
    {
        n/=k;
        res+=n;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll a,b,c;

    while(scanf("%lld %lld %lld", &a,&b,&c)!= EOF)
    {

            cout << oct << fact_pow(b,c)-fact_pow(a-1,c)<<'\n';
}



    return 0;
}
