#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 2;

typedef long long LL;

LL sol[MAXN];

int main()
{
    //freopen("d.in", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0);

    sol[0] = 1;
    for(LL i = 1; i < MAXN ;i++)
        sol[i] = sol[i - 1] + i;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        cout << sol[n] << "\n";
    }


    return 0;
}
