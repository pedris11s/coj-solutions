#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    LL n;
    while(cin >> n)
    {
        n--;
        LL sol;
        if(n % 3 == 0)
            sol = (((((n / 3) % MOD) * ((n + 1) % MOD)) % MOD) * ((n + 2) % MOD)) % MOD;
        else if((n + 1) % 3 == 0)
            sol = ((((((n + 1) / 3) % MOD) * (n % MOD)) % MOD) * ((n + 2) % MOD)) % MOD;
        else if((n + 2) % 3 == 0)
            sol = ((((((n + 2) / 3) % MOD) * (n % MOD)) % MOD) * ((n + 1) % MOD)) % MOD;
        cout << sol << "\n";
    }

    return 0;
}
