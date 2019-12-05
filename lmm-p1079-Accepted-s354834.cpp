//by pter

#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 150;

int M[MAXN][MAXN];
int dp[MAXN][MAXN];

int Max(int a, int b)
{
    return (a >= b) ? a : b;
}


int main()
{
    //freopen("1079.in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                cin >> M[i][j];

        dp[1][1] = M[1][1];
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= i; j++)
            {
                int max = Max(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = M[i][j] + max;
            }

        int sol = -1;
        for(int j = 1; j <= n; j++)
            if(dp[n][j] > sol)
                sol = dp[n][j];

        cout << sol << endl;

        //cleaning
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++)
                dp[i][j] = 0;
    }

    return 0;
}
