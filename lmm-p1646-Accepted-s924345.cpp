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

int n, m;
int val;

int main()
{
    while(SDD(n,m) != EOF)
    {
        int sg = 0;
        FOR(i, n)
        {
            SD(val);
            sg^=val;
        }
        if(sg)
        {
            printf("Vida\n");

        }else{
            printf("Andrea\n");
        }

    }


    return 0;
}
