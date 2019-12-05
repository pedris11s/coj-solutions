#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen(".in", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0);

    int x;
    vector <int> V;
    while(cin >> x)
        V.push_back(x);

    int sol = 0;
    for(int i = 0; i < V.size() - 1; i++)
        for(int j = i + 1; j < V.size(); j++)
            sol = max(sol, __gcd(V[i], V[j]));
    cout << sol << "\n";

    return 0;
}
