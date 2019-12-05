#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

LL exp_mod(LL b, LL e)
{
    if(e == 0)
        return 1;

    if(e % 2 == 0)
    {
        LL r = exp_mod(b, e / 2);
        return (r * r) % MOD;
    }
    return ((b % MOD) * (exp_mod(b, e - 1) % MOD)) % MOD;
}

int main()
{
    LL n;
    while(cin >> n)
        cout << exp_mod(3, n) << endl;

    return 0;
}
