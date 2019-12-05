#include <cstdio>
#include <iostream>

using namespace std;

typedef long long huge;

const int MAXN = 100000;

huge sol[MAXN];

void solve()
{
    sol[1] = 1;
    for(int i = 2; i < MAXN; i++)
        sol[i] = sol[i - 1] + 4 * (i - 1);
}

int main()
{
    solve();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << sol[n] << endl;
    }

    return 0;
}
