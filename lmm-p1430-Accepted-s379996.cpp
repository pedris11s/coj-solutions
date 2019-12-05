//by pter

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>//memset()

using namespace std;

const int MAX = 505;
const int MOD = 1000000009;

char M[MAX][MAX];
int dp[MAX][MAX];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof dp);

        for(int i = 0; i < n; i++)
            scanf("%s", M[i]);

        dp[0][0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(dp[i][j] != 0 && M[i][i] != 0)
                {
                    if(i == n - 1 && j == n - 1);
                    else
                    {
                        int ii = i + (M[i][j] - 48);
                        int jj = j + (M[i][j] - 48);

                        if(ii < n)
                            dp[ii][j] = ((dp[ii][j] % MOD) + (dp[i][j] % MOD)) % MOD;
                        if(jj < n)
                            dp[i][jj] = ((dp[i][jj] % MOD) + (dp[i][j] % MOD)) % MOD;
                    }
                }
        cout << dp[n - 1][n - 1] << endl;
    }
    return 0;
}
