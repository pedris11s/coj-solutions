#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1007;
const LL MOD = 1000000007;

LL F[MAXN];
LL TP[MAXN][MAXN];

void precal()
{
    F[0] = 1;
    for(LL i = 1; i < MAXN; i++)
        F[i] = ((F[i - 1] % MOD) * (i % MOD)) % MOD;

    for(int i = 0; i < MAXN; i++)
        TP[i][0] = TP[i][i] = 1;

    for(int i = 2; i < MAXN; i++)
        for(int j = 1; j < i; j++)
            TP[i][j] = ((TP[i - 1][j] % MOD) + (TP[i - 1][j - 1] % MOD)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    precal();
    int n, m;
    cin >> n >> m;

    LL sol = ((((TP[n + 1][m] % MOD) * (F[n] % MOD)) % MOD) * (F[m] % MOD)) % MOD;
    cout << sol << "\n";

    return 0;
}
