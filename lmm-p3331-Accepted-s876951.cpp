#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL sol(LL a, LL b)
{
    if((a == 1 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 1) && (a == 2 && b == 2))
        return 0;
    if(a == 1 && b > 2)
        return b * b - 3 * b + 2;
    if(a > 2 && b == 1)
        return a * a - 3 * a + 2;
    return a * a * b * b - 9 * a * b + 6 * a + 6 * b - 4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        LL a, b;
        cin >> a >> b;
        if(a == 0)
            break;

        cout << sol(a, b) << "\n";
    }

    return 0;
}
