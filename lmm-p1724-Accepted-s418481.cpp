#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int MAX_LOG = 100;

int N, K, M;
int ini[MAXN];
int LCA[MAXN][MAX_LOG];

void build_lca()
{
    for(int j = 1; (1 << j) <= M; j++)
        for(int i = 1; i <= K; i++)
            LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
}

void sol()
{
    for(int i = 0; i < N; i++)
    {
        int nodo = ini[i], m = M, lg = (int)log2(M);
        for(int  j = lg; j > -1; j--)
            if(m - (1 << j) >= 1)
            {
                nodo = LCA[nodo][j];
                m -= (1 << j);
            }
        if(i != N - 1)
            cout << nodo << ' ';
        else
            cout << nodo << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> N >> K >> M;
        for(int i = 0; i < N; i++)
            cin >> ini[i];

        for(int i = 1; i <= K; i++)
        {
            int a;
            cin >> a;
            LCA[i][0] = a;
        }
        build_lca();
        sol();

        for(int i = 0; i <= max(N, K); i++)
            ini[i] = 0;
    }
    return 0;
}
