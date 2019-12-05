#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
            cout << "4\n";
        else
        {
            int mcd = __gcd(a, b);
            int sol = (a / mcd) + (b / mcd);
            cout << 2 * sol << "\n";
        }
    }

    return 0;
}
