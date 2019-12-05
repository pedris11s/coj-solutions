#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1007;

int sol[MAXN];
string A[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> A[i];

        for(int i = 1; i <= N - 1; i++)
            if(A[i] < A[i + 1])
                sol[i] = i + 1;
            else
                sol[i] = -1;
        sol[N] = -1;
        cout << sol[1];
        for(int i = 2; i <= N; i++)
            cout << ' ' << sol[i];
        cout << "\n";
    }

    return 0;
}
