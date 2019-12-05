#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 1e3 + 7;

int sol[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        LL n;
        cin >> n;

        LL sol = (n + 1) * (n + 1) - 1;
        cout << sol << "\n";
    }

    return 0;
}
