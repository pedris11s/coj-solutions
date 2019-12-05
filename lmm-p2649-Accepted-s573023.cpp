#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const LL MOD = 1000003;
const LL INV_MOD = 666669;

LL pot(LL b, LL e)
{
    if(e == 0)
        return 1;
    if(e % 2 == 0)
    {
        LL r = pot(b, e / 2);
        return (r * r) % MOD;
    }
    return ((b % MOD) * (pot(b, e - 1) % MOD)) % MOD;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        LL N;
        cin >> N;

        LL sol = ((pot(4, N + 1) - 1 + MOD) * INV_MOD) % MOD;
        cout << sol << endl;
    }


    return 0;
}
