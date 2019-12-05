#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005

void factores(ll n)
{
    for(ll i = 2; i*i <= n; i++)
    {
        while(n%i==0)
        {
            printf("    %lld\n", i);

            n/=i;
        }
    }
    if(n>1)printf("    %lld\n", n);
}
ll val;
int main()
{
    while(true)
    {
        scanf("%lld", &val);
        if(val < 0)break;
        if(val == 0 || val==1)val=val;
        else{
            factores(val);
        }

        printf("\n");
    }



    return 0;
}
