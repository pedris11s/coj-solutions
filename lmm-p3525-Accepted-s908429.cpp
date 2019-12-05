#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;
const ll MOD = 1000000007;
int arr1[1005];
int arr2[1005];
ll dp[1004][1004];
ll suma[1004][1004];

void pascal()
{
    for(int i = 0; i < 1004; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j==0 || j==i)
            {
                dp[i][j] = 1;
                suma[i][j] = 1;
                if(j==i)
                {
                    suma[i][j]=1+suma[i][j-1];
                }
            }else{
                dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%MOD;
                suma[i][j] = (dp[i][j]+suma[i][j-1])%MOD;
            }
        }
    }
}

int main()
{

    pascal();
    /*for(int i = 0; i <= 10; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j==0 || j==i)
            {
                cout << suma[i][j] << " ";
            }else{
                cout << suma[i][j] << " ";
            }
        }
        cout << endl;
    }*/
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr2[i]);
        }
        ll val = 1;
        for(int i = 0; i < n; i++)
        {
            val*=((suma[arr2[i]][min(arr1[i]-1, arr2[i])])-1);
            val%=MOD;
        }
        printf("%lld\n", val);
    }
    return 0;
}
