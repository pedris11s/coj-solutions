#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10007;

int N, K;
int A[MAX], dp[MAX][15];

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    for(int i = 1; i <= K; i++)
        dp[i][0] = (1 << 30);

    for(int j = 1; j <= N; j++)
        for(int i = 0; i <= K; i++)
        {
            dp[i][j] = (1 << 30);
            for(int k = 1; k * k <= i; k++)
                dp[i][j] = min(dp[i][j], (A[j] - k) * (A[j] - k) + dp[i - k * k][j - 1]);
        }
    int sol = (dp[K][N] == (1 << 30)) ? -1 : dp[K][N];
    cout << sol << endl;



    return 0;
}
