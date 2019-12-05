//by pter

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll f(ll n){
    ll x = n * (n + 1);
    return x * x / 4 + (n + n + 1) * x / 2 + x;
}

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (f(b) - f(a - 1)) % 100 << '\n';
    }
    return 0;
}
