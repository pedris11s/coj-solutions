#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 10;

ll pow_rec(ll b, ll e)
{
    if(e == 0)
        return 1;

    if(e % 2 == 0)
    {
        ll r = pow_rec(b, e / 2);
        return (r * r) % MOD;
    }
    return (b * pow_rec(b, e - 1)) % MOD;
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll b, e;
        cin >> b >> e;

        cout << pow_rec(b, e) << endl;
    }

    return 0;
}
