#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int A[MAXN];

int main()
{
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> A[i];

        sort(A, A + N);
        int X = A[0], Y = 0;
        for(int i = 1; i < N; i++)
            Y += A[i] - X;
        Y /= N;
        cout << "Case " << "#" << k << ": " << X << " " << Y << endl;
    }

    return 0;
}
