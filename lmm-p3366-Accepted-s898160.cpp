#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int N;
int A[MAXN], sol[MAXN];

int maxInt(int a, int b)
{
    int m = -1;
    for(int i = a; i <= b;i++)
        m = max(m, A[i]);
    return m;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];

    int ans = -1;
    for(int i = 0; i < N; i++){
        sol[i] = maxInt(i + 1, N - 1) - A[i];
        if(sol[i] > 0)
            ans = max(ans, sol[i]);
        //cout << sol[i] << endl;
    }
    if(ans == -1)
        ans = 0;
    cout << ans << endl;


    return 0;
}
