#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string sol = "625";
    for(int i = 0; i < n - 1; i++)
        sol += "0";
    cout << sol << "\n";

    return 0;
}
