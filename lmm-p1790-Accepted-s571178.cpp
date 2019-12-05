#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A[10004];

int main()
{
    //freopen(".in", "r", stdin);

    int mini = (1 << 30), maxi = -1;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    mini = A[0], maxi = A[0];
    int sol = 0;
    for(int i = 0; i < N; i++)
        if(A[i] < mini)
            sol++, mini = A[i];
        else if(A[i] > maxi)
            sol++, maxi = A[i];
    cout << sol << endl;

    return 0;
}
