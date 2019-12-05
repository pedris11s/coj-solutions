#include <bits/stdc++.h>

using namespace std;

const int MAXN = 407;

typedef long long LL;

int N;
LL M[MAXN][MAXN], dP[MAXN][MAXN], dNP[MAXN][MAXN];

LL suma(int i, int j, int ii, int jj)
{
    LL a = dP[ii][jj] - dP[i - 1][j - 1];
    LL b = dNP[ii][j] - dNP[i - 1][jj + 1];
    return (LL)(a - b);
}

int main()
{
    //freopen(".in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> M[i][j];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++){
            dP[i][j] = dP[i - 1][j - 1] + M[i][j];
            dNP[i][j] = dNP[i - 1][j + 1] + M[i][j];
        }
    LL sol = -(1e15);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 0; i + k <= N && j + k <= N; k++)
                sol = max(sol, suma(i, j, i + k, j + k));
    cout << sol << "\n";
/*

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            cout << dNP[i][j] << ' ';
        cout << endl;
    }
*/
    return 0;
}
