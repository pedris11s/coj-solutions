#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 105;

int N, T[MAX][MAX], M[MAX][MAX];
string A[MAX];

int lcs(string a, string b)
{
    int sza = a.size() - 1;
    int szb = b.size() - 1;

    for(int i = 0; i <= sza; i++)T[0][i] = 0;
    for(int i = 0; i <= szb; i++)T[i][0] = 0;

    for(int i = 1; i <= sza; i++)
        for(int j = 1; j <= szb; j++)
            if(a[i] == b[j])
                T[i][j] = T[i - 1][j - 1] + 1;
            else
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);

    return T[sza][szb];
}

void floyd_warshall()
{
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                M[i][j] = min(M[i][j], max(M[i][k], M[k][j]));
}

int main()
{
    //freopen(".in", "r", stdin);

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        string cad;
        cin >> cad;
        A[i] = "+" + cad;
    }
    for(int i = 1; i <= N - 1; i++)
        for(int j = i + 1; j <= N; j++)
            M[i][j] = M[j][i] = lcs(A[i], A[j]) + 1;

    floyd_warshall();
    int sol = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sol = max(sol, M[i][j]);
    cout << sol << endl;


    return 0;
}


