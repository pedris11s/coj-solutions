#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;


ll pow_rec(ll e)
{
    if(e == 0)
        return 1;

    if(e % 2 == 0)
    {
        ll r = pow_rec(e / 2);
        return (r * r) % MOD;
    }
    return (2 * pow_rec(e - 1)) % MOD;
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        cout << pow_rec(n - 1) << endl;
    }

    return 0;
}
