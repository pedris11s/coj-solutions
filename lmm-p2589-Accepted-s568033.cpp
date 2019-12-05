#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 16;

int N, K, A[MAXN + 5];
long long dp[(1 << MAXN)][MAXN];
bool mk[(1 << MAXN)][MAXN];

int mod(int n)
{
    return (n < 0) ? -n : n;
}

long long solve(int S, int j)
{
    if((S & (S - 1)) == 0)
        return 1;

    if(!mk[S][j])
    {
        long long sol = 0;
        int ss = S - (1 << j);
        for(int x = 0; x < N; x++)
            if(((1 << x) & ss) && mod(A[j] - A[x]) > K)
                sol += solve(ss, x);

        dp[S][j] = sol;
        mk[S][j] = true;
    }
    return dp[S][j];
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    long long sol = 0;
    for (int i = 0 ; i < N ; i++)
        sol += solve((1 << N) - 1, i);

    cout << sol << endl;

    return 0;
}
