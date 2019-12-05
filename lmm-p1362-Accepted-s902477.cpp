#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        if(a == 0 && b == 0 && c == 0)
            break;

        int mcd = __gcd(a, b);
        if(c % mcd == 0)
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}
