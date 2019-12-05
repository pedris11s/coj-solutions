#include <bits/stdc++.h>

using namespace std;

bool check(string a, string b)
{
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i] && a[i] != b[a.size() - i- 1])
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;

        if(a.size() == b.size() && check(a, b) && check(b, a))
            cout << "YES\n";
        else
            cout << "NO\n";
    }



    return 0;
}
