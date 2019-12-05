#include <bits/stdc++.h>

using namespace std;

int N, M;
long long sol[5000], A[5000], B[5000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N;
    N++;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    cin >> M;
    M++;
    for(int i = 0; i < M; i++)
        cin >> B[i];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            int grado = i + j;
            sol[grado] += A[i] * B[j];
        }

    for(int i = 0; i <= N + M - 2; i++)
        if(i == 0)
            cout << sol[i];
        else
            cout << ' ' << sol[i];
    cout << "\n";

    return 0;
}
