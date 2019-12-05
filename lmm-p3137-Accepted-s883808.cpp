#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b, int c)
{
    if(a + b == c)
        return true;
    if(a - b == c)
        return true;
    if(a * b == c)
        return true;
    if(b != 0 && a / b == c)
        return true;
    if(b != 0 && a % b == c)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(check(a, b, c))
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    return 0;
}
