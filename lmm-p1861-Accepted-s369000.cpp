//by pter & marlone

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 205;

#define FIN 2 * N - 1
#define MIT ((2 * N - 1) / 2) + 1

int M[MAXN][MAXN];
int dp[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    int k = 1;
    while(t--)
    {
        memset(dp, 0, sizeof dp);

        int N;
        scanf("%d", &N);
        for(int i = 1; i <= MIT; i++)
            for(int j = 1; j <= i; j++)
                scanf("%d", &M[i][j]);

        int aux = MIT - 1;
        for(int i = MIT + 1; i <= FIN; i++)
        {
            for(int j = 1; j <= aux; j++)
                scanf("%d", &M[i][j]);

            aux--;
        }

        dp[1][1] = M[1][1];
        for(int i = 2; i <= MIT; i++)
            for(int j = 1; j <= i; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + M[i][j];

        aux = MIT + 1;
        for(int i = MIT + 1; i <= FIN; i++)
        {
            for(int j = 1; j <= aux; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + M[i][j];
            aux--;
        }
        printf("Case %d: %d\n", k, dp[FIN][1]);
        k++;


    }

    return 0;
}
