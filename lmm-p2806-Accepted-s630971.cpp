#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 500007;

int N, A[MAXN], K;
int R[MAXN][50];

void BuildRMQ()
{
    for(int i = 0; i < N; i++)
        R[i][0] = i;

    int lg = (int)log2(N);
    for(int e = 1; e <= lg; e++)
    {
        int fin = N - (1 << e) + 1;
        for(int i = 0; i <= fin; i++)
            if(A[R[i][e - 1]] >= A[R[i + (1 << (e - 1))][e - 1]])
                R[i][e] = R[i][e - 1];
            else
                R[i][e] = R[i + (1 << (e - 1))][e - 1];
            //R[i][e] = max(R[i][e - 1], R[i + (1 << (e - 1))][e - 1]);
    }
}

int Query(int a, int b)
{
    int e = (int)log2(b - a + 1);
    int maxim;
    if(A[R[a][e]] >= A[R[b - (1 << e) + 1][e]])
        maxim = R[a][e];
    else
        maxim = R[b - (1 << e) + 1][e];
    return maxim;
}

int main()
{
    //cout << log2(MAXN);

    //freopen("read.in", "r", stdin);
    cin >> N >> K;
    string cad;
    cin >> cad;
    for(int i = 0; i < cad.size(); i++)
        A[i] = cad[i] - '0';

    BuildRMQ();

    //cout << Query(0, N - 1) << endl;;
    //int size = N - K;
    int size = N - K;
    int ini = 0, fin = N - size;
    vector <int> V;

    //for(int i = 0; i < N; i++)
    //    for(int j = i ; j < N; j++)
    //        cout << i << ' ' << j << ' ' << A[Query(i, j)] << endl;

    while(fin != N)
    {
        int ind = Query(ini, fin);
        V.push_back(A[ind]);
        ini = ind + 1;
        fin++;
        //cout << A[ind] << endl;
        //system("pause");
    }
    for(int i = 0; i < V.size(); i++)
        cout << V[i];
    cout << endl;


    return 0;
}
