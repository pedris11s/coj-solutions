#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 200001;

int N, A[MAXN], Ind[MAXN];
int R[MAXN][50];

void BuildRMQ()
{
    for(int i = 0; i < N; i++)
        R[i][0] = Ind[i];

    int lg = (int)log2(N);
    for(int e = 1; e <= lg; e++)
    {
        int fin = N - (1 << e) + 1;
        for(int i = 1; i <= fin; i++)
            R[i][e] = max(R[i][e - 1], R[i + (1 << (e - 1))][e - 1]);
    }
}

int Query(int a, int b)
{
    int e = (int)log2(b - a + 1);
    int maxim = max(R[a][e], R[b - (1 << e) + 1][e]);
    return maxim;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    for(int i = 0; i < N; i++)
        Ind[A[i]] = i;

    //for(int i = 0; i < N; i++)
    //    cout << Ind[i] << ' ';
    BuildRMQ();

    int sol = 0;
    for(int i = 0; i < N; i++)
    {
        int mxind = Query(A[i] + 1, N);
        int best = mxind - Ind[A[i]] + 1;
        sol = max(sol, best);
    }
    if(sol == 1)
        sol = -1;

    cout << sol << endl;


    return 0;
}
