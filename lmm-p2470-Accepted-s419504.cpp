#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 300005;
const int MAXL = 21;

typedef long long huge;
char s[35];
huge N, K;
huge dp[MAXN + 1][MAXL + 1];

int main()
{
    //freopen("d.in", "r", stdin);

    cin >> N >> K;
    huge ans = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%s",s);
        int size = strlen(s);
        //maxs = max(maxs, size);
        for (int j = 1; j < MAXL; j++)
            dp[i][j] = dp[i - 1][j];

        /*for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= maxs; j++)
                cout << dp[i][j] << ' ';
        }*/

        ans += dp[i][size];
        if (K + 1 <= i)
            ans -= dp[i - K - 1][size];

        dp[i][size]++;
    }

    cout << ans;
    return 0;
}
