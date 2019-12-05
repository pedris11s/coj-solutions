#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 7;
const int INV_MOD = 694488662;

LL TA[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    LL p = 1;
    for(int i = 1; i < MAXN / 2; i++)
    {
        TA[i] = p * p;
        TA[i] = ((TA[i - 1] % MOD) + (TA[i] % MOD)) % MOD;
        p += 2;
    }
    LL n;
    while(cin >> n){
        n = (n & 1) ? n / 2 + 1 : n / 2;
        cout << TA[n] << "\n";
    }

    return 0;
}
