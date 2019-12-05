#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1002;

int N, M;
long long A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    sort(A, A + N);
    long long sol = 0;
    for(int i = 0; i < M; i++)
        if(A[i] <= 0)
            sol += -A[i];

    cout << sol << "\n";


    return 0;
}
