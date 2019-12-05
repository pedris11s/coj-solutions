#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int A[300005];

int main()
{
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1);
    int p = 1, Max = 0;
    for(int i = N; i >= 0; i--, p++)
        if(A[i] + p > Max)
            Max = A[i] + p;

    //cout << Max  << ' ' << may<< endl;
    int sol = 0;
    for(int i = 1; i <= N; i++)
        if(A[i] + N >= Max)
            sol++;

    cout << sol << endl;

    return 0;
}
