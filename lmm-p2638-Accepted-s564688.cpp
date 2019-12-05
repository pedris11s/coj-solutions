#include <cstdio>
#include <iostream>

using namespace std;

int dp[2001][2001];
bool mk[2001][2001];

const int MOD = 100999;

int sol(int n, int k)
{
    if(!mk[n][k])
    {
        int r = 0;
        if(n - k >= 0 && k > 0)
            r = (r + sol(n - k, k - 1)) % MOD;

        if(k > 0)
            r = (r + sol(n, k - 1)) % MOD;

        dp[n][k] = r;
        mk[n][k] = true;

    }
    return dp[n][k];
}

int main()
{
    //casos base
    for(int i = 0; i < 2001; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 1;

        mk[i][0] = true;
        mk[0][i] = true;
    }
    for (int i = 1 ; i <= 2000 ; i++)
        sol(i, i);
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        //cout << N << endl;
        cout << dp[N][N] << endl;

    }

    return 0;
}
