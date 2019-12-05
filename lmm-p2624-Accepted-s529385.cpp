#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int A[110];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int M, N;
        cin >> M >> N;
        for(int i = 0; i < N; i++)
            cin >> A[i];

        sort(A, A + N);
        int sol = 0;
        for(int i = 0; i < N; i++)
        {
            if(M - A[i] >= 0)
                sol++, M = M - A[i];

            if(M == 0)
                break;
        }
        cout << sol << endl;
    }

    return 0;
}
