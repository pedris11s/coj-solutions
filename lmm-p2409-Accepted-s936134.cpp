#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    string cad;
    int a, b;
    cin >> cad >> a >> b;
    cout << cad << " " << max(b - a, a - b) << "\n";

    return 0;
}
