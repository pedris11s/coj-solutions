#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;
const int MOD = 1000000007;

int sol[MAX + 7];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    sol[0] = sol[1] = 1;
    for(int i = 2; i <= MAX; i++){
        sol[i] = sol[i - 1] + sol[i - 2];
        sol[i] %= MOD;
    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << sol[n] << "\n";
    }

    return 0;
}
