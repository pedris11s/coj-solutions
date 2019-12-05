#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct matriz{
    LL Mat[100][100];
    matriz(){};
};

const LL MOD = 1000000007;

LL N, A, Q;
matriz M, Uno;

matriz Mult(matriz A, matriz B)
{
    matriz sol;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int k = 1; k <= N; k++){
                int a = (A.Mat[i][k] * B.Mat[k][j]) % MOD;
                sol.Mat[i][j] = ((sol.Mat[i][j] % MOD) + (a % MOD)) % MOD;
            }
    return sol;
}

matriz pow(matriz b, int e)
{
    if(e == 0)
        return Uno;

    if(e % 2 == 0)
    {
        matriz x = pow(b, e / 2);
        return Mult(x, x);
    }
    return Mult(b, pow(b, e - 1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> A;
    for(int i = 1; i <= A; i++)
    {
        int a, b;
        cin >> a >> b;
        M.Mat[a][b]++;
    }
    cin >> Q;

    for(int i = 1; i <= N; i++)
        Uno.Mat[i][i] = 1LL;

    matriz x = pow(M, Q);
    cout << x.Mat[1][N] << "\n";
/*
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1 ; j <= N; j++)
            cout << x.Mat[i][j] << ' ';
        cout << endl;
    }
*/
    return 0;
}
