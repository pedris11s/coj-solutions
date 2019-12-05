//by pter
//algorithm: dinamyc programing

#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 105;

int f, c;
int M[MAX][MAX];
int dp[MAX][MAX];

int main()
{
    //freopen("1378.in", "r", stdin);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> f >> c;
        for(int i = 1; i <= f; i++)
            for(int j = 1; j <= c; j++)
                cin >> M[i][j];

        //primera fila de dp
        for(int j = 1; j <= c; j++)
            dp[1][j] = M[1][j];

        for(int i = 2; i <= f; i++)
            for(int j = 1; j <= c; j++)
            {
                int max = -1;
                for(int k = j - 1; k <= j + 1; k++)
                    if(dp[i - 1][k] > max)
                        max = dp[i - 1][k];

                dp[i][j] = M[i][j] + max;
            }
        int sol = -1;
        for(int j = 1; j <= c; j++)
            if(dp[f][j] > sol)
                sol = dp[f][j];

        cout << sol << endl;
        
        //limpiando la matriz
        for(int i = 1; i <= f; i++)
            for(int j = 1; j <= c; j++)
                dp[i][j] = 0;
    }

    return 0;
}

