#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const ULL MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    ULL n;
    while(cin >> n)
    {
        n--;
        ULL sol;
        if(n % 4 == 0)
            sol = (((((((n / 4) % MOD) * ((n + 1) % MOD)) % MOD) * ((n + 2) % MOD)) % MOD) * ((n + 3) % MOD)) % MOD;
        else if((n + 1) % 4 == 0)
            sol = ((((((((n + 1) / 4) % MOD) * ((n) % MOD)) % MOD) * ((n + 2) % MOD)) % MOD) * ((n + 3) % MOD)) % MOD;
        else if((n + 2) % 4 == 0)
            sol = ((((((((n + 2) / 4) % MOD) * ((n) % MOD)) % MOD) * ((n + 1) % MOD)) % MOD) * ((n + 3) % MOD)) % MOD;
        else if((n + 3) % 4 ==0)
            sol = ((((((((n + 3) / 4) % MOD) * ((n) % MOD)) % MOD) * ((n + 2) % MOD)) % MOD) * ((n + 1) % MOD)) % MOD;

        cout << sol << "\n";
    }

    return 0;
}
