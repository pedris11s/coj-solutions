#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2501;

int ta[MAXN], dp[2501];

int main()
{
    //freopen("river.in", "r", stdin);
    //freopen("river.out", "w", stdout);

    int N;
    cin >> N >> ta[0];
    for(int i = 1; i <= N; i++)
    {
        cin >> ta[i];
        ta[i] += ta[i - 1];
    }

    for(int i = 1; i <= N; i++)
    {
        dp[i] = (1 << 30);
        for(int j = 1; j <= i; j++)
            dp[i] = min(dp[i], dp[i - j] + ta[0] + ta[j]);
    }
    cout << dp[N] - ta[0] << endl;

    return 0;
}
