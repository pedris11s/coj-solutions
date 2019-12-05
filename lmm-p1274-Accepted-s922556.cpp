#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define SD(n) scanf("%d", &n)
#define SDD(n,m) scanf("%d%d",&n,&m)
using namespace std;

typedef long long ll;
const ll MOD = 1000003;
#define MAXN 1000005

ll dp[101][101];
int dp2[101][101];
void built()
{
    for(int i = 2; i <= 100; i++)
    {
        int n = i;
        for(int j = 2; j*j<=n; j++)
        {
            while(n%j==0)
            {
                dp2[i][j]++;
                n/=j;
            }
        }
        if(n>1)
        {
            dp2[i][n]++;
        }
    }
}
bool isprime(int n)
{
    if(n==2)return true;
    if(n%2==0)return false;
    for(int i = 3; i*i<=n; i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
vector<int> sol[104];
bool marca[104];
int main()
{
    built();
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 2; j <= 100; j++)
        {
            dp[i][j] = dp2[i][j]+dp[i-1][j];
        }
    }
    for(int i = 2; i<= 100; i++)
    {
        if(isprime(i))marca[i] = true;
    }
    for(int i =2; i <= 100; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            if(marca[j])
            {
                sol[i].pb(dp[i][j]);
            }
        }
    }
    int n;
    while(true)
    {
        scanf("%d", &n);
        if(!n)break;
        int cantDig = log10(n)+1;
        printf("%3d", n);
        printf("! =");
        int contador = 0;
        int canti = sol[n].size();
        for(int i = 0; i < canti; i++)
        {
            printf("%3d", sol[n][i]);
            contador++;
            if(contador==15)
            {
                if(i<canti-1)
                {
                    printf("\n");
                    printf("      ");

                }

                contador = 0;
            }
        }
        printf("\n");
    }



    return 0;
}
