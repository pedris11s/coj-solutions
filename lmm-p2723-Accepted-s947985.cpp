#include <bits/stdc++.h>

using namespace std;

int N, K, A[1005];

int main()
{
    cin >> K >> N;

    for(int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + 1 + N);

    if(A[1] + A[2] + A[3] > K)
        cout << "0\n";
    else
    {
        int sol = 3;
        for(int i = 4; i <= N; i++)
            if(A[i] + A[1] + A[2] <= K)
                sol++;
        cout << sol << "\n";
    }
    return 0;
}

