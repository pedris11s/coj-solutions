#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool prime(LL n)
{
    if(n == 0 || n == 1)return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(LL i = 3; i * i <= n; i += 2)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        LL n;
        cin >> n;
        if(prime(n - 2))
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}
