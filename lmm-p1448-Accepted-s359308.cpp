//by pter

#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long huge;

const huge MAX = 100005;

huge M[MAX][5];
huge dp[MAX][5];

huge Min(huge a, huge b)
{
    return (a <= b) ? a : b;
}

int main()
{
    //freopen("1448.in", "r", stdin);
    huge c = 1;
    while(true)
    {
        huge n;
        cin >> n;

        if(n == 0)
            break;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 3; j++)
                cin >> M[i][j];

        //filas uno y dos
        dp[1][1] = 0;
        dp[1][2] = M[1][2];
        dp[1][3] = M[1][3] + dp[1][2];
        dp[2][1] = M[2][1] + dp[1][2];
        dp[2][2] = M[2][2] + Min(dp[2][1], Min(dp[1][2], dp[1][3]));
        dp[2][3] = M[2][3] + Min(dp[2][2], Min(dp[1][2], dp[1][3]));

        for(int i = 3; i <= n; i++)
            for(int j = 1; j <= 3; j++)
            {
                //cout << "entre" << endl;
                if(j == 1)
                    dp[i][j] = M[i][j] + Min(dp[i - 1][j], dp[i - 1][j + 1]);
                else if(j == 2)
                    dp[i][j] = M[i][j] + Min(Min(dp[i][j - 1], dp[i - 1][j - 1]),
                                             Min(dp[i - 1][j], dp[i - 1][j + 1]));
                else if(j == 3)
                    dp[i][j] = M[i][j] + Min(dp[i][j - 1], Min(dp[i - 1][ j - 1], dp[i - 1][j]));
            }
        cout << c << ". " << dp[n][2] << endl;
        c++;
    }

    return 0;
}
