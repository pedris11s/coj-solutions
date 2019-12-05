//by pter

#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    ll a, b;

    while(t--)
    {
        cin >> a >> b;

        ll sum = 0;

        for(int i = a; i <= b; i++)
            sum += i * (i + 1) * (i + 2);

        cout << sum % 100 << "\n";
    }
    return 0;
}
