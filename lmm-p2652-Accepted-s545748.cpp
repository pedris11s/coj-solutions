#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int ct(int m, int n)
{
    return min(m / 2, n);
}

int main()
{
    int m, n, k;
    cin >> m >> n >> k;

    int sol = 0, a, b;
    for(int i = 0; i <= k; i++)
    {
        a = min(m, i);
        b = min(n, k - i);
        sol = max(sol, ct(m - a, n - b));
    }
    cout << sol << endl;

    return 0;
}
