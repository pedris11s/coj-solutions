#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    LL N;
    cin >> N;

    LL sol = N * N + 1;
    if(N == 1)
        sol = 2;
    cout << sol << '\n';


    return 0;
}
