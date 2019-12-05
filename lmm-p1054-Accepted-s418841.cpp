  #include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int dp[10005];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,p,d;
        cin >> n >> m;
        for(int i = 0; i != m; i++)
        {
            cin >> p >> d;
            for(int j = d; j <= n; j++)
                dp[j] = max(dp[j], dp[j - d] + p);
        }
        cout << dp[n] << endl;
        for(int i = 0; i <= n; i++)
            dp[i] = 0;
    }
    return 0;
}
      
