#include <bits/stdc++.h>

using namespace std;

#define zero(x) memset(x,0,sizeof(x))
#define fo(i,n) for(int i =0;i<n;i++)
#define X first
#define Y second

typedef long long ll;

ll dp[1004];
int main()
{
     for(int i = 1; i <= 5; i++)
    {
        dp[i] = (1<<(i-1));
    }
    for(int i = 6; i <= 1000; i++)
    {
        ll cont = 0;
        for(int j = 0; j <= i-2; j++)
        {
            ll izq = j;
            ll der = i-2-j;
            cont+= (izq*der)+1;
        }
        dp[i] = cont+dp[i-1];
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

