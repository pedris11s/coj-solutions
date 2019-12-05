#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;
const int MAX = 1000005;
const int MOD = 1000000000;

huge n, dp[MAX][50], A[MAX];

int main()
{
    //freopen("pr.in", "r", stdin);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int k = n; k > 0; k--)
            for(int j = 0; j < 3; j++)
                dp[k][(j + A[i] % 3) % 3] = (dp[k][(j + A[i] % 3) % 3] + dp[k - 1][j]) % MOD;

    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }*/

    huge sol = 0;
    for(int i = 1; i <= n; i++)
        sol = (sol + dp[i][0]) % MOD;

    cout << sol << endl;
    return 0;
}

