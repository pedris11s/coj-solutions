#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, p;
        string cad;
        cin >> n >> cad >> p;
        if(cad == "odd")
            cout << 2 * p << "\n";
        else
            cout << (2 * p) - 1 << "\n";
    }

    return 0;
}
