#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long huge;

const int MOD = 1000000000;

huge exp_mod(huge b, huge e)
{
    if(e == 0)
        return 1;

    if(e % 2 == 0)
    {
        huge r = exp_mod(b, e / 2);
        return (r * r) % MOD;
    }
    return ((b % MOD) * (exp_mod(b, e - 1) % MOD)) % MOD;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        huge a, b;
        cin >> a >> b;
        cout << exp_mod(a, b) << endl;

    }

    return 0;
}
