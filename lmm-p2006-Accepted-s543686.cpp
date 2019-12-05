#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2013;

int N, L;
int dp[MAXN], h[MAXN], w[MAXN], ta[MAXN], maximo[MAXN][MAXN];

int main()
{
    cin >> N >> L;
    for(int i = 1; i <= N; i++)
        cin >> h[i] >> w[i];

    for(int i = 1; i <= N; i++)
    {
        maximo[i][i] = h[i];
        for(int j = i + 1; j <= N; j++)
            if(h[j] > maximo[i][j - 1])
                maximo[i][j] = h[j];
            else
                maximo[i][j] = maximo[i][j - 1];
    }
    ta[1] = w[1];
    for(int i = 2; i <= N; i++)
        ta[i] = ta[i - 1] + w[i];

    int sumh = 0;
    for(int i = 1; i <= N; i++)
    {
        sumh += h[i];
        dp[i] = sumh;
        for(int j = i; j > 0; j--)
        {
            if(ta[i] - ta[j - 1] > L)
                break;

            if(dp[i] > dp[j - 1] + maximo[j][i])
                dp[i] = dp[j - 1] + maximo[j][i];
        }
    }
    cout << dp[N] << endl;

    return 0;
}

