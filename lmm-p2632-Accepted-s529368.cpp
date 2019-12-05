#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL M[150][150], dp[150][150], dp2[150][150];

int main()
{
    LL N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++)
            cin >> M[i][j];

   //dp2[1][1] = M[1][1] * M[1][1];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + M[i][j];
            //if(i  > 1)
                dp2[i][j] = max(dp2[i - 1][j - 1], dp2[i - 1][j]) + (M[i][j] * M[i][j]);
        }

    LL sol1 = 0, sol2 = 0;
    for(int i = 1; i <= N; i++)
    {
        sol1 = max(sol1, dp[N][i]);
        sol2 = max(sol2, dp2[N][i]);
    }

    cout << sol2 << ' ' << sol1 << endl;
    cout << char((sol2 % 26) + 'a') << char((sol1 % 26) + 'a') << endl;;

    return 0;
}

