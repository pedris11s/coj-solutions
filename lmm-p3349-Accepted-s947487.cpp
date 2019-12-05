#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

LL pot(LL e)
{
    if(e == 0)
        return 1;
    if(e % 2 == 0)
    {
        LL r = pot(e / 2);
        return (r * r) % MOD;
    }
    return (2LL * pot(e - 1)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        LL n;
        cin >> n;

        LL sol = (pot(n) - 1);
        cout << (sol + MOD) % MOD << "\n";
    }

    return 0;
}
