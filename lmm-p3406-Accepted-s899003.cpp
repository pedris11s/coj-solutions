#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string cad;
        cin >> cad;

        int n = cad.size();
        while(n--)
            cad += "0";
        cout << cad << "\n";
    }


    return 0;
}
